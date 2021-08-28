/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "a2" //pls dont forget your task's name
#define maxn int(1e5);
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
#define Fin(name) freopen(name ".inp", "r", stdin)
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
int d[26][26], path[26];
vector<int> G[26];

bool bfs(int s, int e)
{
    d[s][s] = 0;
    path[s] = 0;
    queue<int> qu;
    qu.push(s);
    if (s == e)
        return 1;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        for (int v : G[u])
        {
            if (!path[v])
            {
                path[v] = path[u] + 1;
                qu.push(v);
            }
            if (v == e)
            {
                d[s][e] = path[e];
                return 1;
            }
        }
    }
    return 0;
}

void resetPath()
{
    forup(int, i, 0, 25) G[i].clear();
    memset(path, 0, sizeof(path));
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    forup(int, i, 1, t)
    {
        int res(-1);
        forup(int, i, 0, 25) G[i].clear();
        string s;
        cin >> s;
        int k(0);
        cin >> k;
        char u, v;
        for (int j(0); j < k && cin >> u >> v; ++j)
            G[u - 'A'].pb(v - 'A');
        forup(int, e, 0, 25)
        {
            bool ok(1);
            int cp(0);
            forup(int, c, 0, s.size() - 1)
            {
                memset(path, 0, sizeof(path));
                if (!bfs(s[c] - 'A', e))
                {
                    ok = 0;
                    break;
                }
                else
                    cp += d[s[c] - 'A'][e];
            }
            if (!ok)
                continue;
            if (res == -1 || cp < res)
                res = cp;
        }
        cout << "Case #" << i << ": " << res;
        if (i < t)
            cout << '\n';
    }
    return 0;
}