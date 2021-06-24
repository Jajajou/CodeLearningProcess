#define task "newton"
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#include <bits/stdc++.h>
using namespace std;
int n, m, pm, pc, cham[int(1e6)], chac[int(1e6)], xoa[int(1e6)];
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
vector<int> a[int(1e6)], b[int(1e6)], res;
void init()
{
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
}
void dfsm(int u)
{
    // for (int i = 0; i < a[u].size(); i++)
    for (int v : a[u])
    {
        // int v = a[u][i];
        if (!cham[v])
        {
            cham[v] = u;
            dfsm(v);
        }
    }
}
void dfsc(int u)
{
    // for (int i = 0; i < b[u].size(); i++)
    for (int v : b[u])
    {
        // int v = b[u][i];
        if (!chac[v])
        {
            chac[v] = u;
            dfsc(v);
        }
    }
}
int k(0), q[101] = {};
void bf(int f)
{
    k = 0;
    while (f != n + 1)
    {
        q[++k] = f;
        f = chac[f];
    }
}

void dfs(int u)
{
    for (int v : b[u])
    {
        if (v == pc)
        {
            bf(u);
            if (k > 2)
                return;
        }
        if (!xoa[v] && !chac[v])
        {
            chac[v] = u;
            dfs(v);
        }
    }
}
int main()
{
    //fastio();
    init();
    int x, y;
    scanf("%d%d%d", &n, &pm, &pc);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        b[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        sort(b[i].begin(), b[i].end());
    cham[pm] = n + 1;
    dfsm(pm);
    chac[pc] = n + 1;
    dfsc(pc);
    for (int i = 1; i <= n; i++)
    {
        if ((cham[i] > 0) && (chac[i] > 0))
        {
            res.push_back(i);
            xoa[i] = 1;
        }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d\n", res[i]);
    forup(i, 1, n) chac[i] = 0;
    chac[pc] = n + 1;
    dfs(pc);
    if (k > 2)
    {
        cout << k << endl;
        fordown(i, k, 1) cout << q[i] << endl;
    }
    else
        cout << 0;
}
