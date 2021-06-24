/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "sconnect" //pls dont forget your task's name
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
    int u(0), v(0);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
}

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
        else
            low[u] = min(low[u], num[v]);
    }
    if (!(num[u] - low[u]))
    {
        int f(0);
        do
        {
            f = st.top();
            st.pop();
            cout << f << ' ';
            low[f] = num[f] = maxn;
        } while (u != f);
        cut;
    }
}

void solve()
{
    forup(i, 1, n) if (!num[i]) visit(i);
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}