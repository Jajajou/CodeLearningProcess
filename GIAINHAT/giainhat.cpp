/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "giainhat" //pls dont forget your task's name
#define maxn int(1e4) + 14
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
int n(0), m(0), u[maxn] = {}, v[maxn] = {};
vector<int> G[maxn] = {};

void read()
{
    cin >> n >> m;
    forup(i, 1, m)
    {
        cin >> u[i] >> v[i];
        G[u[i]].push_back(v[i]);
    }
}

int graphCore[maxn] = {}, belongGraphNum[maxn] = {}, tmp(0), num[maxn] = {}, low[maxn] = {}, cnt(0);
stack<int> st;
void visit(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : G[u])
    {
        if (!num[v])
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        low[u] = min(low[u], num[v]);
    }
    if (!(num[u] - low[u]))
    {
        graphCore[++tmp] = u;
        int f(0);
        do
        {
            f = st.top();
            st.pop();
            belongGraphNum[f] = tmp;
            low[f] = num[f] = maxn;
        } while (u != f);
    }
}

void solve()
{
    forup(i, 1, n) if (!num[i]) visit(i);
    forup(i, 1, m)
    {
        if (belongGraphNum[u[i]] - belongGraphNum[v[i]])
        {
            cout << u[i] << ' ' << v[i] << endl;
            cout << belongGraphNum[u[i]] - belongGraphNum[v[i]] << endl;
            graphCore[belongGraphNum[u[i]]] = 0;
        }
    }
    int res(0);
    forup(i, 1, tmp)
    {
        if (graphCore[i] > 1)
            ++res;
    }
    cout << res;
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}