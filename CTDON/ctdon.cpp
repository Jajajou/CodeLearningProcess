/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ctdon" //pls dont forget your task's name
#define maxn int(1e5) + 3
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
int n(0), m(0), u(0), v(0), path[maxn] = {}, s(0);
bool visited[maxn] = {};
vector<int> G[maxn];

void read()
{
    scanf("%d %d %d\n", &n, &m, &s);
    while (m--)
    {
        scanf("%d %d\n", &u, &v);
        G[u].push_back(v);
    }
}

void dfs(int u)
{
    // visited[u] = 1;
    for (auto v : G[u])
    {
        if (!path[v])
        {
            path[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    boost();
    IO();
    read();
    dfs(s);
    vector<int> res;
    res.push_back(s);
    int f(path[s]);
    while (f - s)
    {
        res.push_back(f);
        f = path[f];
    }
    res.push_back(s);
    cout << res.size() - 1 << endl;
    fordown(i, res.size() - 1, 0) cout << res[i] << ' ';
}