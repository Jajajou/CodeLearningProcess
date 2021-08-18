/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "flightDiscount" //pls dont forget your task's name
#define maxn int(2e5) + 15
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
struct Node
{
    int node;
    ll cost;
    bool useDiscount;
    Node(int _node, ll _cost, bool _useDiscount) { node = _node, cost = _cost, useDiscount = _useDiscount; }
    inline const bool operator<(const Node &m) const { return useDiscount == m.useDiscount ? cost > m.cost : useDiscount > m.useDiscount; }
};
vector<ii> G[maxn];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0);
    ll u(0), v(0), w(0);
    cin >> n >> m;
    while (cin >> u >> v >> w)
        G[u].pb({v, w});
    vector<vector<ll>> dis(n + 1, vector<ll>(2, ll(1e15)));
    pri_q<Node> q;
    q.push({1, 0LL, (bool)0});
    while (!q.empty())
    {
        Node u(q.top());
        q.pop();
        if (u.node == n && u.useDiscount)
            return cout << u.cost, 0;
        for (ii v : G[u.node])
        {
            if (dis[v.fi][(int)(u.useDiscount)] > u.cost + v.se)
                q.push({v.fi, dis[v.fi][(int)(u.useDiscount)] = u.cost + v.se, u.useDiscount});
            if (!u.useDiscount && dis[v.fi][(int)(!u.useDiscount)] > u.cost + v.se / 2)
                q.push({v.fi, dis[v.fi][(int)(!u.useDiscount)] = u.cost + v.se / 2, !u.useDiscount});
        }
    }
    return 0;
}