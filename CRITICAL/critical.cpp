/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "critical" //pls dont forget your task's name
#define maxn int(2e4) + 24
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
int n(0), m(0), f[maxn] = {}, res(0);
vector<int> G[maxn];

void read()
{
    int u(0), v(0);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int low[maxn] = {}, num[maxn] = {}, cnt(0), path[maxn] = {}, components[maxn] = {}, k(0);
bool criticalNode[maxn] = {};
void visit(int u)
{
    components[u] = k;
    f[u] = 1;
    low[u] = num[u] = ++cnt;
    for (int v : G[u])
    {
        if (!num[v])
        {
            path[v] = u;
            visit(v);
            f[u] += f[v];
            low[u] = min(low[u], low[v]);
        }
        else if (path[u] != v)
            low[u] = min(low[u], num[v]);
    }
}

void solve()
{
    forup(i, 1, n)
    {
        if (!num[i])
        {
            ++k;
            visit(i);
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