/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "coldwat" //pls dont forget your task's name
#define maxn int(1e5)
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), m(0);
vector<int> G[maxn];

void read()
{
    cin >> n >> m;
    int x(0), y(0), z(0);
    while (cin >> x >> y >> z)
    {
        G[x].pb(y);
        G[x].pb(z);
    }
}

int degree[maxn] = {};
void dfs(int u)
{
    for (int v : G[u])
    {
        if (!degree[v])
        {
            degree[v] = degree[u] + 1;
            dfs(v);
        }
    }
}

void solve()
{
    dfs(1);
    forup(int, i, 1, n) cout << degree[i] + 1 << endl;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    return 0;
}