/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "chainblock" //pls dont forget your task's name
#define maxn int(8e5)
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
const int Log2N(log2(maxn));
int n(0), q(0), par[maxn][Log2N], depth[maxn], pathLen[maxn];
vector<int> adj[maxn], f[maxn];
vector<int> color;
vector<int> G[maxn];

void dfs_initLCA(int u, int cp)
{
    for (int v : adj[u])
        if (v != cp)
        {
            depth[v] = depth[u] + 1;
            par[v][0] = u;
            forup(int, i, 1, Log2N - 1) par[v][i] = par[par[v][i - 1]][i - 1];
            dfs_initLCA(v, u);
        }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int k(depth[u] - depth[v]);
    fordown(int, i, Log2N - 1, 0) if (getBit(k, i)) u = par[u][i];
    if (u == v)
        return u;
    fordown(int, i, Log2N - 1, 0) if (par[u][i] - par[v][i])
        u = par[u][i],
        v = par[v][i];
    return par[u][0];
}

void init()
{
    forup(int, i, 1, n)
    {
        adj[i].clear();
        f[i].clear();
        depth[i] = pathLen[i] = 0;
        forup(int, j, 0, log2(n)) par[i][j] = 0;
    }
}

void dfs(int u, int cp, int &res)
{
    for (int v : adj[u])
        if (v != cp)
        {
            dfs(v, u, res);
            if (!pathLen[v])
                ++res;
            maximize(pathLen[u], pathLen[v] - 1);
        }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    forup(int, T, 1, t)
    {
        int res(0);
        init();
        cin >> n;
        for (int i(1), u(0), v(0); i <= n - 1 && cin >> u >> v; ++i)
            adj[u].pb(v), adj[v].pb(u);
        dfs_initLCA(1, 1);
        for (int i(1), x(0); i <= n && cin >> x; ++i)
            f[x].pb(i);
        forup(int, i, 1, n) if ((int)f[i].size() >= 2)
        {
            int u(f[i][0]);
            for (int v : f[i])
                u = lca(u, v);
            for (int v : f[i])
                pathLen[v] = depth[v] - depth[u];
        }
        dfs(1, 1, res);
        cout << "Case #" << T << ": " << res;
        if (T < t)
            cout << '\n';
    }
    return 0;
}