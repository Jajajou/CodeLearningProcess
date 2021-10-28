/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "aznet" // pls dont forget your task's name
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
    int findRoot(int u)
    {
        if (u != root[u])
            root[u] = findRoot(root[u]);
        return root[u];
    }
    bool join(int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);
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
} * dsu;
int n(0), m(0);
vector<iii> adj;
vector<int> a, b;
vector<bool> mst;

void reset(int n, int m)
{
    a.clear();
    b.clear();
    adj.clear();
    mst.clear();
    a.resize(n, 0);
    b.resize(n, 0);
    adj.resize(m);
    mst.resize(m, 0);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int T(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        reset(n, m);
        forup(int, i, 1, n - 1) cin >> a[i];
        forup(int, i, 1, n - 1) cin >> b[i];
        for (auto &[u, v, c] : adj)
            cin >> u >> v >> c;
        int takeA(0), takeB(0);
        dsu = new DSU();
        (*dsu).init(n);
        for (auto [u, v, c] : adj)
            if (c == 1)
                takeA += (*dsu).join(u, v);
        dsu = new DSU();
        (*dsu).init(n);
        for (auto [u, v, c] : adj)
            if (c == 2)
                takeB += (*dsu).join(u, v);
        int x(0), y(0), sum(INT_MAX), cnt(0);
        forup(int, i, max(0, n - takeB - 1), min(n - 1, takeA)) if (sum > a[i] + b[n - 1 - i])
        {
            sum = a[i] + b[n - i - 1];
            x = i;
        }
        y = n - x - 1;
        forup(int, i, 0, m - 1)
        {
            auto [u, v, c] = adj[i];
            if (c == 1)
                mst[i] = (*dsu).join(u, v);
        }
        dsu = new DSU();
        (*dsu).init(n);
        forup(int, i, 0, m - 1) if (mst[i])
        {
            auto [u, v, c] = adj[i];
            cnt += (*dsu).join(u, v);
        }
        forup(int, i, 0, m - 1) if (cnt < x && !mst[i])
        {
            auto [u, v, c] = adj[i];
            if (c == 1)
                cnt += (mst[i] = (*dsu).join(u, v));
        }
        forup(int, i, 0, m - 1)
        {
            auto [u, v, c] = adj[i];
            if (c == 2)
                cnt += (mst[i] = (*dsu).join(u, v));
        }
        forup(int, i, 0, m - 1) if (mst[i]) cout << i + 1 << ' ';
        cut;
    }
    return 0;
}