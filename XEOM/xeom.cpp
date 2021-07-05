/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "xeom" //pls dont forget your task's name
#define maxn int(4e4) + 44
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
int x(0), y(0), p(0), n(0), m(0);
vector<int> G[maxn];

void read()
{
    cin >> x >> y >> p >> n >> m;
    p = min(p, x + y);
    int u(0), v(0);
    while (m-- && cin >> u >> v)
    {
        G[u].pb(v);
        G[v].pb(u);
    }
}

int d1[maxn] = {}, d2[maxn] = {}, dn[maxn] = {};
bool visited[maxn] = {};
void resetPath() { forup(int, i, 1, n) visited[i] = 0; }

void bfs(int s, int depth[])
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
    {
        int u(q.front());
        q.pop();
        for (int v : G[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    resetPath(), bfs(1, d1);
    resetPath(), bfs(2, d2);
    resetPath(), bfs(n, dn);
    int res(INT_MAX);
    forup(int, i, 1, n) res = min(res, (d1[i] * x + d2[i] * y + dn[i] * p));
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