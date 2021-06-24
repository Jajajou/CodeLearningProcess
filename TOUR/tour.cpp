/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tour" //pls dont forget your task's name
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
int n(0), m(0), des[maxn] = {}, k(0), path[maxn] = {};
vector<int> G[maxn], res;

void read()
{
    cin >> n >> k >> m >> des[k + 1];
    des[0] = des[k + 1];
    forup(i, 1, k) cin >> des[i];
    int u(0), v(0);
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void resetPath(int s)
{
    forup(i, 1, n) path[i] = 0;
    path[s] = n + 1;
}

void bf(int f, int s)
{
    int cp[int(1e3)], d(0);
    while (f - s)
    {
        cp[++d] = f;
        f = path[f];
    }
    fordown(i, d, 1)
        res.push_back(cp[i]);
}

void bfs(int s, int f)
{
    resetPath(s);
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u(q.front());
        q.pop();
        for (int v : G[u])
        {
            if (!path[v])
            {
                path[v] = u;
                if (v == f)
                {
                    bf(f, s);
                    return;
                }
                q.push(v);
            }
        }
    }
}

void solve()
{
    forup(i, 1, k + 1) bfs(des[i - 1], des[i]);
    cout << res.size() << "\n"
         << des[k + 1] << ' ';
    forup(i, 0, res.size() - 1) cout << res[i] << ' ';
}

int main()
{
    boost();
    IO();
    read();
    solve();
}