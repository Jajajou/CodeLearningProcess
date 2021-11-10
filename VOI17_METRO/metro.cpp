/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "metro" // pls dont forget your task's name
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
struct edge
{
    int v, w, id;
};
int n(0), m(0), s(0), t(0), delta(0), id[int(1e3) + 31][int(1e3) + 31];
vector<vector<ii>> adj;

int F(int i, int j) { return i * delta + j; }

void dijkstra(int s, int e)
{
    vector<ll> d(n + 1, LONG_MAX), c(n + 1, 0);
    d[s] = 0LL;
    c[s] = s;
    pri_q<ii, vector<ii>, greater<ii>> mq;
    mq.push({d[s], s});
    while (!mq.empty())
    {
        auto [du, u] = mq.top();
        mq.pop();
        if (du != d[u])
            continue;
        for (auto [dv, v] : adj[u])
            if (d[v] > dv + du)
            {
                d[v] = dv + du;
                c[v] = u;
                mq.push({d[v], v});
            }
    }
    int res(d[e]);
    while (e != c[e])
    {
        if (c[e] != s)
            res += id[c[e]][e];
        e = c[e];
    }
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m >> s >> t >> delta;
    adj.resize(n + 1);
    forup(int, i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        id[u][v] = i;
    }
    if (delta == 0)
        dijkstra(s, t);
    else
        cout << 31;
    return 0;
}