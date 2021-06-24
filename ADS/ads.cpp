/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ads" //pls dont forget your task's name
#define maxn int(1e4)
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
int n(0), m(0), u(0), v(0), path[maxn] = {}, res(0);
bool searched[maxn] = {};
vector<int> G[maxn];

void read()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v),
            G[v].push_back(u);
    }
}

void dfs(int u)
{
    for (int v : G[u])
    {
        if (path[v] && path[u] - v && !searched[v])
            ++res;
        if (!path[v] && !searched[v])
        {
            path[v] = u;
            dfs(v);
        }
    }
    searched[u] = 1;
}

int main()
{
    boost();
    IO();
    read();
    dfs(1);
    cout << res;
}