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
int n, m, x, y, Low[int(1e5)], Num[int(1e5)], k = 0, cha[int(1e5)], child[int(1e5)];
vector<vector<int>> a(int(2e4) + 1);
long long res = 0, f[int(1e5) + 1];

int cnt = 0, mlt[int(1e5) + 1];
void dfs(int u)
{
    mlt[u] = k;
    cnt++;
    Low[u] = Num[u] = cnt;
    f[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (Num[v])
        {
            if (cha[u] != v)
                Low[u] = min(Low[u], Num[v]);
        }
        else
        {
            cha[v] = u;
            child[u]++;
            dfs(v);
            Low[u] = min(Low[v], Low[u]);
            f[u] += f[v];
        }
    }
}

bool Node[int(1e5)];
void findnode()
{
    for (int i = 1; i <= n; i++)
    {
        if (i != cha[i])
        {
            int u = cha[i];
            if (Low[i] >= Num[u])
            {
                if ((Num[u] == 1) && (child[u] < 2))
                    Node[u] = 0;
                else
                    Node[u] = 1;
            }
        }
    }
}

int main()
{
    boost();
    IO();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!Num[i])
        {
            k = i;
            dfs(i);
        }
    }
    findnode();
    for (int i = 1; i <= n; i++)
    {
        if (Node[i])
        {
            long long tmp = 0, d = 0;
            for (int j = 0; j < a[i].size(); j++)
            {
                int v = a[i][j];
                if ((cha[v] == i) && (Low[v] >= Num[i]))
                {
                    d += f[v];
                    tmp += f[v] * (f[mlt[i]] - f[v] - 1);
                }
            }
            tmp += (f[mlt[i]] - d - 1) * (d);
            tmp /= 2;
            res += tmp;
        }
    }
    cout << fixed << setprecision(2) << float(res) / n;
    return 0;
}