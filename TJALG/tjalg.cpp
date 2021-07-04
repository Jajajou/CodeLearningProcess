/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tjalg" //pls dont forget your task's name
#define maxn int(1e4) + 14
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
int n(0), m(0), f[maxn] = {}, res(0);
vector<int> G[maxn];

void read()
{
    int u(0), v(0);
    cin >> n >> m;
    while (cin >> u >> v)
        G[u].pb(v);
}

int low[maxn] = {}, num[maxn] = {}, cnt(0);
bool checked[maxn] = {};
stack<int> st;
void visit(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : G[u])
    {
        if (checked[v])
            continue;
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
        ++res;
        int v(0);
        do
        {
            v = st.top();
            st.pop();
            checked[v] = 1;
        } while (v - u);
    }
}

void solve()
{
    forup(int, i, 1, n) if (!num[i]) visit(i);
    cout << res;
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