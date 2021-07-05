/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "graph_" //pls dont forget your task's name
#define maxn int(1e4) + 14
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, end) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
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
int n(0), m(0), criticalNode(0), criticalEdge(0);
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

int low[maxn] = {}, num[maxn] = {}, checkedNode[maxn] = {}, cnt(0);
void visit(int u, int cp)
{
    int childNode(0);
    low[u] = num[u] = ++cnt;
    for (int v : G[u])
    {
        if (v - cp)
        {
            if (!num[v])
            {
                visit(v, u);
                ++childNode;
                low[u] = min(low[u], low[v]);
                criticalEdge += (low[v] == num[v]);
                if (u == cp and childNode >= 2 || u - cp and low[v] >= num[u])
                {
                    if (!checkedNode[u])
                        checkedNode[u] = ++criticalNode;
                }
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
}

void solve()
{
    forup(int, u, 1, n) if (!num[u]) visit(u, u);
    cout << criticalNode << ' ' << criticalEdge;
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