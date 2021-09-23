/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "qhroad" //pls dont forget your task's name
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
struct DSU
{
    int n;
    vector<int> root, depth;
    void init(int _n)
    {
        n = _n;
        root.resize(n + 1, 0);
        depth.resize(n + 1, 0);
        forup(int, i, 1, n) root[i] = i;
    }
    int find(int u)
    {
        if (root[u] != u)
            root[u] = find(root[u]);
        return root[u];
    }
    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return 0;
        if (depth[u] == depth[v])
            ++depth[u];
        if (depth[u] < depth[v])
            root[v] = u;
        else
            root[u] = v;
        return 1;
    }
} dsu;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0), q(0);
    cin >> n >> m >> q;
    dsu.init(n);
    int res(n);
    vector<ii> adj(m);
    vector<bool> del(m, 0);
    vector<int> ans(q), cp(q);
    for (auto &[u, v] : adj)
        cin >> u >> v;
    for (int &v : cp)
        cin >> v, del[--v] = 1;
    forup(int, i, 0, m - 1) if (!del[i]) res -= dsu.merge(adj[i].fi, adj[i].se) ? 1 : 0;
    fordown(int, i, ans.size() - 1, 0)
    {
        ans[i] = res;
        res -= dsu.merge(adj[cp[i]].fi, adj[cp[i]].se) ? 1 : 0;
    }
    for (int v : ans)
        cout << v << endl;
    return 0;
}