/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "onepath" //pls dont forget your task's name
#define maxn int(1e5) + 1
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
int n(0), m(0), s(0), f(0), path[maxn] = {};
bool visited[maxn] = {};
vector<int> G[maxn];

void read()
{
    scanf("%d %d %d %d\n", &n, &m, &s, &f);
    while (m--)
    {
        int u(0), v(0);
        scanf("%d %d\n", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    path[s] = 0;
}

void dfs(int u)
{
    sort(G[u].begin(), G[u].end());
    visited[u] = 1;
    for (auto v : G[u])
    {
        if (!visited[v])
        {
            path[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    dfs(s);
    if (!path[f])
    {
        cout << -1;
        exit(0);
    }
    else
    {
        vector<int> res;
        while (path[f])
        {
            res.push_back(f);
            f = path[f];
        }
        res.push_back(s);
        fordown(i, res.size() - 1, 0) cout << res[i] << ' ';
    }
}