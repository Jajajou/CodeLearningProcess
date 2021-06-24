/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "bfs" //pls dont forget your task's name
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
int n(0), m(0), s(0), f(0), path[maxn] = {};
vector<int> G[maxn];

void read()
{
    int u(0), v(0);
    cin >> n >> m >> s >> f;
    while (m--)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
    path[s] = n + 1;
}

void bf()
{
    vector<int> res;
    while (f - (n + 1))
    {
        res.push_back(f);
        f = path[f];
    }
    cout << res.size() << endl;
    fordown(i, res.size() - 1, 0) cout << res[i] << ' ';
}

void bfs()
{
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
                    bf();
                    exit(0);
                }
                q.push(v);
            }
        }
    }
    cout << 0;
}

int main()
{
    boost();
    IO();
    read();
    bfs();
}