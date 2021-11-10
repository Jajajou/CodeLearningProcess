/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "network" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
#define maxn 101001
#define elif else if
#define pri_q priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define Fin(name) freopen(name ".inp", "r", stdin)
#define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin

template <class val>
val getBit(val x, val pos)
{
    return x >> pos & 1;
}
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }
template <class val>
const void maximize(val &a, val b)
{
    a = max(a, b);
}
template <class val>
const void minimize(val &a, val b)
{
    a = min(a, b);
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), k(0), a(0), b(0);
vector<int> adj[1001];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> k >> a >> b;
    int u(0), v(0);
    while (cin >> u >> v)
        adj[u].pb(v), adj[v].pb(u);
    function<int(int, int)> bfs = [&](int s, int e)
    {
        int d[n + 1] = {0};
        vector<bool> visited(n + 1, 0);
        queue<int> mq;
        mq.push(s);
        visited[s] = 1;
        while (!mq.empty())
        {
            int u(mq.front());
            mq.pop();
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = 1, d[v] = d[u] + 1;
                    mq.push(v);
                }
                if (v == e)
                    return d[e];
            }
        }
        return d[e];
    };
    if (n <= 100 && k == 2)
    {
        int res(0);
        forup(int, i, 1, n) forup(int, j, i + 1, n)
        {
            int cp(bfs(i, j));
            if (cp >= a && cp <= b)
                ++res;
        }
        cout << res;
    }
    elif (n <= 100 && k == 3)
    {
        int res(0);
        forup(int, i, 1, n) forup(int, j, i + 1, n) forup(int, k, j + 1, n)
        {
            int cp(bfs(i, j) + bfs(j, k) + bfs(k, i));
            cp /= 2;
            if (cp >= a && cp <= b)
                ++res;
        }
        cout << res;
    }
    elif (n <= 100 && k == 4)
    {
        int res(0);
        function<bool(int, int, int, vector<bool> &, vector<bool> &)> dfs = [&dfs](int i, int j, int k, vector<bool> &vital, vector<bool> &visited)
        {
            if (i == j || i == k)
                return vital[i] = 1;
            visited[i] = 1;
            for (int v : adj[i])
                if (!visited[v])
                    vital[i] = dfs(v, j, k, vital, visited);
            return vital[i];
        };
        function<void(queue<int> &, vector<int> &, vector<bool> &)> multisourceBfs = [&](queue<int> &mq, vector<int> &d, vector<bool> &visited)
        {
            visited.resize(n + 1, 0);
            while (!mq.empty())
            {
                int u(mq.front());
                mq.pop();
                for (int v : adj[u])
                    if (!visited[v])
                    {
                        visited[v] = 1, d[v] = d[u] = 1;
                        mq.push(v);
                    }
            }
        };
        forup(int, i, 1, n) forup(int, j, i + 1, n) forup(int, k, j + 1, n)
        {
            vector<int> d(n + 1, 0);
            vector<bool> visited(n + 1, 0), vital(n + 1, 0);
            vital[i] = dfs(i, j, k, vital, visited);
            queue<int> mq;
            forup(int, x, 1, n) if (vital[x]) mq.push(i);
            int tmp(mq.size());
            multisourceBfs(mq, d, visited);
            forup(int, x, 1, n) if (!vital[x])
            {
                if (tmp + d[x] <= b && tmp + d[x] >= a)
                    ++res;
            }
        }
        cout << res;
    }
    else cout << -1;
    return 0;
}