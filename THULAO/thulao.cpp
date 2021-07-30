/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "thulao" //pls dont forget your task's name
#define maxn int(1e5) + 15
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), m(0), path[maxn] = {}, d[maxn];
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
    path[1] = 1;
}

void dijkstra(int s)
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
                path[v] = u;
            }
        }
    }
}

void solve()
{
    dijkstra(1);
    int F(n), tmp(d[n]), res(0);
    while (F - 1)
    {
        chosenPath.pb({F, path[F]});
        F = path[F];
    }
    for (ii p : chosenPath)
    {
        for (ii &cpU : G[p.fi])
        {
            if (cpU.se == p.se)
            {
                cpU.fi *= 2;
                break;
            }
        }
        for (ii &cpU : G[p.se])
        {
            if (cpU.se == p.fi)
            {
                cpU.fi *= 2;
                break;
            }
        }
        dijkstra(1);
        res = max(res, d[n] - tmp);
        for (ii &cpU : G[p.fi])
        {
            if (cpU.se == p.se)
            {
                cpU.fi >>= 1;
                break;
            }
        }
        for (ii &cpU : G[p.se])
        {
            if (cpU.se == p.fi)
            {
                cpU.fi >>= 1;
                break;
            }
        }
    }
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    return 0;
}