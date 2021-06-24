/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "kttree" //pls dont forget your task's name
#define maxn int(1e3) + 3
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
int n(0), m(0);
bool visited[maxn] = {};
vector<int> G[maxn];

void read()
{
    cin >> n >> m;
    int q(m), u(0), v(0);
    while (q--)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u)
{
    visited[u] = 1;
    for (int v : G[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

void solve()
{
    bool x((n - m) == 1), y(1);
    dfs(1);
    forup(i, 1, n)
    {
        if (!visited[i])
        {
            y = 0;
            break;
        }
    }
    cout << ((x && y) ? "1" : "0");
    forup(i, 1, n) visited[i] = 0,
                   G[i].clear();
}

int main()
{
    boost();
    IO();
    int t(0);
    cin >> t;
    while (t--)
    {
        read();
        solve();
        cut;
    }
}