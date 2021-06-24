/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "dulich" //pls dont forget your task's name
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
int n(0), m(0), cnt(0), low[maxn] = {}, num[maxn] = {}, u[maxn] = {}, v[maxn] = {}, path[maxn] = {};
vector<int> G[maxn], edgeDirection[maxn];

void resetPath()
{
    forup(i, 2, n) path[i] = 0;
}

void read()
{
    cin >> n >> m;
    forup(i, 1, m)
    {
        cin >> u[i] >> v[i];
        G[u[i]].push_back(v[i]);
    }
}

int gCore[maxn] = {}, gNodeCount[maxn] = {};
stack<int> st;
void visit(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    for (int v : G[u])
    {
        if (!num[v])
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!gCore[v])
            low[u] = min(low[u], num[v]);
    }
    if (low[u] - num[u])
        return;
    gCore[u] = u;
    ++gNodeCount[u];
    int v(st.top());
    while (u - v)
    {
        gCore[v] = u;
        ++gNodeCount[u];
        st.pop();
        v = st.top();
    }
    st.pop();
}

int tmp(0);
void recreateGraph()
{
    forup(i, 1, m)
    {
        if (gCore[u[i]] - gCore[v[i]])
        {
            ++tmp;
            u[tmp] = gCore[u[i]];
            v[tmp] = gCore[v[i]];
        }
    }
    m = tmp;
    forup(i, 1, m)
    {
        G[u[i]].push_back(v[i]);
        edgeDirection[u[i]].push_back(0);
        G[v[i]].push_back(u[i]);
        edgeDirection[v[i]].push_back(1);
    }
}

int d1[maxn] = {}, d2[maxn] = {};
void dfs0(int u)
{
    for (int i(0); i < G[u].size(); ++i)
    {
        if (!edgeDirection[u][i])
        {
            int v(G[u][i]);
            if (!path[v])
            {
                path[v] = u;
                dfs0(v);
            }
            if (d1[v])
                d1[u] = max(d1[u], d1[v] + gNodeCount[u]);
        }
    }
}

void dfs1(int u)
{
    for (int i(0); i < G[u].size(); ++i)
    {
        if (edgeDirection[u][i])
        {
            int v(G[u][i]);
            if (!path[v])
            {
                path[v] = u;
                dfs1(v);
            }
            if (d2[v])
                d2[u] = max(d2[u], d2[v] + gNodeCount[u]);
        }
    }
}

void solve()
{
    forup(i, 1, n) if (!gCore[i])
    {
        cnt = 0;
        visit(i);
    }
    forup(i, 1, n) G[i].clear();
    recreateGraph();
    d1[1] = d2[1] = gNodeCount[1];
    forup(i, 2, m) if (!path[gCore[i]])
    {
        dfs0(gCore[i]);
    }
    resetPath();
    forup(i, 2, m) if (!path[gCore[i]])
    {
        dfs1(gCore[i]);
    }
}

int main()
{
    boost();
    IO();
    read();
    solve();
    int res(0);
    forup(i, 1, m) if (d1[u[i]] and d2[v[i]])
    {
        res = max(res, d1[u[i]] + d2[v[i]] - gNodeCount[1]);
    }
    cout << res;
    return 0;
}