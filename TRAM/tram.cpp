/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tram" //pls dont forget your task's name
#define maxn int(3e3) + 33
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
int n(0), Rank[maxn] = {}, path[maxn] = {}, res(0), u(0), v(0);
bool ctr[maxn] = {};
vector<int> G[maxn];

void read()
{
    cin >> n;
    forup(i, 1, n)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    path[1] = n + 1;
}

void bf(int u, int v)
{
    ctr[v] = 1;
    while (v - u)
    {
        ctr[u] = 1;
        u = path[u];
    }
}

bool check(0);
void dfs1(int u)
{
    if (check)
        return;
    for (int v : G[u])
    {
        if (!path[v])
        {
            path[v] = u;
            dfs1(v);
        }
        else if (path[u] != v)
        {
            bf(u, v);
            check = 1;
            return;
        }
        if (check)
            return;
    }
}

void newGraph()
{
    ctr[n + 1] = 1;
    forup(u, 1, n)
    {
        if (ctr[u])
        {
            for (int v : G[u])
            {
                if (!ctr[v])
                {
                    G[n + 1].push_back(v);
                    G[v].push_back(n + 1);
                }
            }
        }
    }
}

void dfs2(int u)
{
    for (int v : G[u])
    {
        if (!ctr[v] && !Rank[v])
        {
            Rank[v] = Rank[u] + 1;
            res = max(res, Rank[v]);
            dfs2(v);
        }
    }
}

void solve()
{
    dfs1(1);
    newGraph();
    dfs2(n + 1);
    cout << res;
}

int main()
{
    boost();
    IO();
    read();
    solve();
}