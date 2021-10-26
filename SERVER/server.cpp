/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "server" // pls dont forget your task's name
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
int n(0), m(0), d[maxn];
vector<ii> G[maxn], chosenPath;

void read()
{
    cin >> n >> m;
    int u(0), v(0), c(0);
    while (cin >> u >> v >> c)
    {
        G[u].pb({c, v});
        G[v].pb({c, u});
    }
}

int dijkstra(int s)
{
    forup(int, i, 1, n) d[i] = INT_MAX;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    d[s] = 0;
    while (!q.empty())
    {
        int u(q.top().se), cu(q.top().fi);
        q.pop();
        if (cu != d[u])
            continue;
        for (ii it : G[u])
        {
            int v(it.se), cv(it.fi);
            if (d[v] > d[u] + cv)
            {
                d[v] = d[u] + cv;
                q.push({d[v], v});
            }
        }
    }
    int res(0);
    forup(int, i, 1, n) if (i != s) res += d[i];
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    int res(INT_MAX);
    forup(int, i, 1, n) minimize(res, dijkstra(i));
    cout << res;
    return 0;
}