/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "nkpolice" //pls dont forget your task's name
#define maxn int(1e5) + 15
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
    int u(0), v(0);
    while (m-- && cin >> u >> v)
    {
        G[u].pb(v);
        G[v].pb(u);
    }
}

int tail[maxn] = {}, low[maxn] = {}, num[maxn] = {}, depth[maxn] = {}, cnt(0), sT[maxn][18] = {{0}};
bool joint[maxn] = {};
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
                ++childNode;
                depth[v] = depth[u] + 1;
                sT[v][0] = u;
                visit(v, u);
                low[u] = min(low[u], low[v]);
                joint[u] = (u == cp && childNode >= 2 || u - cp && low[v] >= num[u]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
    tail[u] = cnt;
}

void sparseTable()
{
    sT[1][0] = 1;
    for (int j(1); 1 << j <= n; ++j)
        forup(int, i, 1, n)
        {
            sT[i][j] = sT[sT[i][j - 1]][j - 1];
        }
}

bool inComponent(int u, int root) { return (num[root] <= num[u] && num[u] <= tail[root]); }

int root(int v, int u)
{
    for (int i = 0; i <= 17; ++i)
        if (u & 1 << i)
            v = sT[v][i];
    return v;
}

bool solve(int k)
{
    if (!k)
    {
        int a(0), b(0), g1(0), g2(0);
        cin >> a >> b >> g1 >> g2;
        if (num[g1] > num[g2])
            swap(g1, g2);
        return inComponent(a, g2) - inComponent(b, g2);
    }
    else
    {
        int a(0), b(0), c(0);
        cin >> a >> b >> c;
        int pA(inComponent(a, c) ? root(a, c) : 0), pB(inComponent(b, c) ? root(b, c) : 0);
        if (!pA and !pB)
            return 1;
        if (pA == pB)
            return 1;
        if (!pA && low[pB] < num[c])
            return 1;
        if (!pB && low[pA] < num[c])
            return 1;
        if (pA && pB && low[pA] < num[c] && low[pB] < num[c])
            return 1;
    }
    return 0;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    visit(1, 1);
    sparseTable();
    int q(0);
    cin >> q;
    while (q--)
    {
        int k(0);
        cin >> k;
        cout << ((solve(k - 1)) ? "yes\n" : "no\n");
    }
    return 0;
}