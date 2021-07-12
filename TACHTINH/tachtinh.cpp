/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tachtinh" //pls dont forget your task's name
#define maxn int(2e5) + 25
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

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), a[maxn] = {}, sum(0);
vector<int> G[maxn];

void read()
{
    cin >> n;
    forup(int, i, 1, n) cin >> a[i], sum += a[i];
    int u(0), v(0);
    while (cin >> u >> v)
    {
        G[u].pb(v);
        G[v].pb(u);
    }
}

int depth[maxn] = {};
bool visited[maxn] = {};
void dfs(int u)
{
    depth[u] = a[u];
    visited[u] = 1;
    for (int v : G[u])
    {
        if (!visited[v])
        {
            dfs(v);
            depth[u] += depth[v];
        }
    }
}

void solve()
{
    dfs(1);
    int res(INT_MAX);
    forup(int, i, 1, n) res = min(res, abs(sum - 2 * depth[i]));
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