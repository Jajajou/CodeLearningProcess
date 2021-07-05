/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "kdl" //pls dont forget your task's name
#define maxn int(5e4)
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), x(0);
vector<int> G[maxn];

void read()
{
    cin >> n >> x;
    int u(0), v(0);
    while (cin >> u >> v)
    {
        G[u].pb(v);
        G[v].pb(u);
    }
}

int depth[maxn] = {}, path[maxn] = {}, cp(0), furthest(0);
void dfs(int u)
{
    for (int v : G[u])
    {
        if (!path[v])
        {
            path[v] = u;
            depth[v] += depth[u] + 1;
            if (depth[v] > furthest)
            {
                furthest = depth[v];
                cp = v;
            }
            dfs(v);
        }
    }
}

int findRoot(int u) { return u == path[u] ? path[u] : findRoot(path[u]); }

void solve()
{
    path[x] = x;
    dfs(x);
    forup(int, i, 1, n) path[i] = (depth[i] == 1) ? i : path[i];
    int res(0), k(findRoot(cp));
    forup(int, i, 1, n) res = (k != findRoot(i)) ? max(res, depth[cp] + depth[i]) : res;
    cout << res + 1;
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