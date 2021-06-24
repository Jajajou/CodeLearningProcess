/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "move" //pls dont forget your task's name
#define maxn int(2e4)
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
int n(0), s(0), f(0), t[202] = {}, path[202] = {}, diff(-1);
vector<int> G[202], res;

void read()
{
    cin >> n >> s >> f;
    forup(i, 1, n) cin >> t[i];
    int u(0), v(0);
    while (cin >> u >> v)
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void resetPath(int s)
{
    forup(i, 1, n) path[i] = 0;
    path[s] = n + 1;
}

int temPath[202] = {}, d(0);
void bf(int f, int s)
{
    d = 0;
    while (f - s)
    {
        temPath[++d] = f;
        f = path[f];
    }
}

bool bfs(int k)
{
    resetPath(s);
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u(q.front());
        q.pop();
        if (!(u - f))
        {
            bf(f, s);
            return 1;
        }
        for (int v : G[u])
        {
            if (!path[v] && abs(t[v] - t[u]) <= k)
            {
                path[v] = u;
                q.push(v);
            }
        }
    }
    return 0;
}

void binarySearch(int l, int r)
{
    while (l <= r)
    {
        int mid(l + (r - l) / 2);
        if (bfs(mid))
        {
            diff = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
}

void show()
{
    cout << diff;
    if (diff + 1)
    {
        cout << "\n"
             << s;
        fordown(i, d, 1) res.push_back(temPath[i]);
        forup(i, 0, res.size() - 1) cout << ' ' << res[i];
    }
}

int main()
{
    boost();
    IO();
    read();
    binarySearch(1, maxn);
    show();
}