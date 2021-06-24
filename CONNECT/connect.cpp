/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "connect" //pls dont forget your task's name
#define maxn int(1e5) + 15
#define cut printf("\n")
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
int n(0), m(0);
bool visited[maxn] = {};
vector<vector<int>> G(int(1e6) + 16);

void read()
{
    int u(0), v(0);
    scanf("%d %d\n", &n, &m);
    while (m--)
    {
        scanf("%d %d\n", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u)
{
    printf("%d ", u);
    visited[u] = 1;
    for (int v : G[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void solve()
{
    forup(i, 1, n)
    {
        if (!visited[i])
        {
            dfs(i);
            cut;
        }
    }
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}