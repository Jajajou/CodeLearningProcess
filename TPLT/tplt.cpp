/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tplt" //pls dont forget your task's name
#define maxn int(1e5) + 15
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, begin, end) x + begin, x + begin + end
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
    int u(0), v(0);
    while (cin >> u >> v)
    {
        G[u].pb(v);
        G[v].pb(u);
    }
}

int mlt[maxn] = {}, countChild[maxn] = {}, k(0);
bool visited[maxn] = {};
void dfs(int u)
{
    visited[u] = 1;
    mlt[u] = k;
    for (int v : G[u])
    {
        if (!visited[v])
        {
            mlt[v] = k;
            ++countChild[mlt[v]];
            dfs(v);
        }
    }
}

void solve()
{
    forup(int, i, 1, n) if (!visited[i])++ k, dfs(i);
    sort(allArr(countChild, 1, k));
    cout << k << ' ' << countChild[k] + 1;
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