/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "lca" //pls dont forget your task's name
#define maxn 1001
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
const int Log2n(log2(maxn));
int n(0), m(0), par[maxn][Log2n], depth[maxn];
vector<int> adj[maxn];

void reset()
{
    forup(int, i, 1, maxn) adj[i].clear();
    forup(int, i, 1, maxn) forup(int, j, 0, Log2n) par[i][j] = 0;
    forup(int, i, 1, maxn) depth[i] = 0;
}

void dfs(int u)
{
    for (int v : adj[u])
    {
        depth[v] = depth[u] + 1;
        par[v][0] = u;
        forup(int, i, 1, Log2n - 1) par[v][i] = par[par[v][i - 1]][i - 1];
        dfs(v);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int k(depth[u] - depth[v]);
    fordown(int, i, Log2n - 1, 0) if (getBit(k, i)) u = par[u][i];
    if (u == v)
        return u;
    fordown(int, i, Log2n - 1, 0) if (par[u][i] != par[v][i])
        u = par[u][i],
        v = par[v][i];
    return par[u][0];
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
        cin >> n;
        bool root[n];
        memset(root, true, sizeof(root));
        for (int i(1), f; i <= n && cin >> f; ++i)
            if (f != 0)
            {
                for (int j(0), v; j < f && cin >> v; ++j)
                    adj[i].pb(v), root[v] = 0;
            }
        int r(0);
        forup(int, i, 1, n) par[i][0] = i;
        forup(int, i, 1, n) if (root[i])
        {
            r = i;
            break;
        }
        dfs(r);
        cin >> m;
        cout << "Case " << T << ": \n";
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
        reset();
    }
    return 0;
}