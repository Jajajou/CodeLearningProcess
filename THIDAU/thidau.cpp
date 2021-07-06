/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "thidau" //pls dont forget your task's name
#define maxn int(3e5) + 35
#define pri_q priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), m(0), team[maxn] = {};
pair<int, int> match[maxn];
vector<int> G[maxn];

void read()
{
    scanf("%d\n%d", &n, &m);
    forup(int, i, 1, m) scanf("%d %d\n", &match[i].first, &match[i].second);
}

void reset()
{
    forup(int, i, 1, n) G[i].clear(), team[i] = 0;
}

bool check_bfs()
{
    queue<int> q;
    q.push(match[1].first);
    team[match[1].first] = 1;
    while (!q.empty())
    {
        int u(q.front());
        q.pop();
        for (int v : G[u])
        {
            if (!team[v])
            {
                team[v] = (team[u] == 2) ? 1 : 2;
                q.push(v);
            }
            else if (team[v] == team[u])
                return 0;
        }
    }
    return 1;
}

int res(0);
void binarySearch(int l, int r)
{
    if (l > r)
        return;
    int mid(r + l >> 1);
    reset();
    forup(int, i, 1, mid) G[match[i].second].pb(match[i].first), G[match[i].first].pb(match[i].second);
    if (check_bfs())
    {
        res = mid;
        binarySearch(mid + 1, r);
    }
    else
        binarySearch(l, mid - 1);
}

void solve()
{
    binarySearch(1, m);
    printf("%d", res + 1);
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