/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "message" //pls dont forget your task's name
#define maxn int(1e5) + 15
#define cut cout << endl
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), m(0), res[maxn] = {}, cnt(0);
bool visited[maxn] = {};
vector<int> G[maxn];

void read()
{
    int u(0), v(0);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
}

void dfs(int u)
{
    for (int v : G[u])
    {
        if (!visited[v])
        {
            visited[v] = 1;
            dfs(v);
        }
    }
}

void solve()
{
    forup(i, 1, n) if (!visited[i]) dfs(i);
    fordown(i, n, 1)
    {
        if (!visited[i])
        {
            res[++cnt] = i;
            dfs(i);
        }
    }
    cout << cnt << endl;
    forup(i, 1, cnt) cout << res[i] << ' ';
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}