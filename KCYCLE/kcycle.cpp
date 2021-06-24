/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "kcycle" //pls dont forget your task's name
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
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), m(0), k(0), checkPole[maxn] = {}, path[maxn] = {}, reversePole[maxn] = {};
vector<int> G[maxn];

void read()
{
    int u(0), v(0);
    cin >> n >> m >> k;
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    path[1] = n + 1;
    k = 0;
}

void bf(int f)
{
    k = 0;
    int cp[maxn] = {};
    while (f - (n + 1))
    {
        cp[++k] = f;
        f = path[f];
    }
    forup(i, 1, k) reversePole[i] = cp[k - i + 1];
}

void show(int u)
{
    for (int v : G[u])
    {
        checkPole[v] = 1;
    }
    int j(1);
    while (!checkPole[reversePole[j]])
        ++j;
    cout << k - j + 1 << endl;
    forup(i, j, k) cout << reversePole[i] << ' ';
}

void dfs(int u)
{
    bool ok(0);
    if (k)
        return;
    for (int v : G[u])
    {
        if (!path[v])
        {
            path[v] = u;
            ok = 1;
            dfs(v);
        }
    }
    if (!ok)
    {
        bf(u);
        show(u);
    }
}

int main()
{
    boost();
    IO();
    read();
    dfs(1);
}