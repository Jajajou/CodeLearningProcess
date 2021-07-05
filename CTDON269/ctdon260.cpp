/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ctdon260" //pls dont forget your task's name
#define maxn int(1e5) + 15
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
int n(0), m(0), low[maxn] = {}, num[maxn] = {}, cnt(0);
vector<int> G[maxn], onlyTreeGraph[maxn];

void read()
{
    cin >> n >> m;
    int u(0), v(0);
    while (cin >> u >> v)
    {
        G[u].pb(v);
        G[v].pb(u);
    }
}

int path[maxn] = {};
void visit(int u)
{
    low[u] = num[u] = ++cnt;
    for (int v : G[u])
    {
        if (!num[v])
        {
            path[v] = u;
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else if (path[u] != v)
            low[u] = min(low[u], num[v]);
    }
}

bool visited[maxn] = {};
void dfs(int u, int &child)
{
    ++child, visited[u] = 1;
    for (int v : onlyTreeGraph[u])
        if (!visited[v])
            dfs(v, child);
}

void solve()
{
    forup(int, i, 1, n) if (!num[i]) cnt = 0, visit(i);
    forup(int, i, 2, n) if (num[i] > 1 && low[i] == num[i]) { onlyTreeGraph[path[i]].pb(i), onlyTreeGraph[i].pb(path[i]); }
    int res(0);
    forup(int, i, 1, n) if (!visited[i])
    {
        int cp(0);
        dfs(i, cp);
        res += cp * (cp - 1) / 2 - (cp - 1);
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