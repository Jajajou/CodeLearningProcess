/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "wishes" //pls dont forget your task's name
#define maxn int(1e5) + 5
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
using namespace std;
int n(0), m(0), res(0);
bool visited[maxn] = {}, dad[maxn] = {};
vector<int> a[maxn];

void read()
{
    scanf("%d %d\n", &n, &m);
    int u(0), v(0);
    forup(i, 1, m)
    {
        scanf("%d %d\n", &u, &v);
        a[u].push_back(v);
    }
}

void dfs(int u)
{
    if (!a[u].size())
        return;
    forup(v, 0, a[u].size() - 1)
    {
        if (!visited[a[u][v]])
        {
            visited[a[u][v]] = 1;
            dfs(a[u][v]);
        }
    }
}

void solve()
{
    forup(u, 1, n)
    {
        if (!visited[u])
        {
            visited[u] = 1;
            dad[u] = 1;
            dfs(u);
        }
    }
    memset(visited, 0, sizeof(visited));
    fordown(u, n, 1)
    {
        if (dad[u] && !visited[u])
        {
            ++res;
            dfs(u);
        }
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
    cout << res;
}