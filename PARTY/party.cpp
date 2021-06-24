/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "party" //pls dont forget your task's name
#define maxn int(2e3) + 23
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
int n(0), path[maxn] = {}, res(0), d(0);
vector<int> G[maxn];

void read()
{
    int x(0);
    cin >> n;
    forup(i, 1, n)
    {
        cin >> x;
        if (x == -1)
        {
            path[i] = n + 1;
        }
        else
            G[x].push_back(i);
    }
}

void dfs(int u)
{
    ++d;
    res = max(res, d);
    for (int v : G[u])
    {
        if (!path[v])
        {
            path[v] = u;
            dfs(v);
        }
    }
    --d;
}

void solve()
{
    forup(i, 1, n)
    {
        if (path[i] == n + 1)
        {
            d = 0;
            dfs(i);
        }
    }
    cout << res;
}

int main()
{
    boost();
    IO();
    read();
    solve();
}