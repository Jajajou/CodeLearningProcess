/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "khopcau" //pls dont forget your task's name
#define maxn int(1e5) + 15
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
int n(0), m(0), low[maxn] = {}, num[maxn] = {}, cnt(0);
vector<int> G[maxn];

void read()
{
    cin >> n >> m;
    int x(0), y(0);
    while (m--)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

int criticalEdge(0), criticalNode(0), CriticalNode[maxn] = {}, checkedNode[maxn] = {};
vector<pair<int, int>> CriticalEdge;
void visit(int u, int cp)
{
    int childNode(0);
    low[u] = num[u] = ++cnt;
    for (int v : G[u])
        if (v - cp)
        {
            if (!num[v])
            {
                visit(v, u);
                ++childNode;
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[v])
                    ++criticalEdge,
                        CriticalEdge.push_back(make_pair(v, u));
                if (u == cp and childNode >= 2 || u - cp and low[v] >= num[u])
                {
                    if (!checkedNode[u])
                        checkedNode[u] = CriticalNode[++criticalNode] = u;
                }
            }
            else
                low[u] = min(low[u], num[v]);
        }
}

void solve()
{
    forup(i, 1, n) if (!num[i]) visit(i, i);
    cout << criticalNode << " " << criticalEdge << endl;
    forup(i, 1, criticalNode)
    {
        cout << CriticalNode[i] << endl;
    }
    for (pair<int, int> x : CriticalEdge)
    {
        cout << x.first << " " << x.second << endl;
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