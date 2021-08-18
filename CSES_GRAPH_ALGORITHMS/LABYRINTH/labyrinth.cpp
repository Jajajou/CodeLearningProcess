/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "labyrinth" //pls dont forget your task's name
#define maxn 101001
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

template <class val>
val getBit(val x, val pos)
{
    return x >> pos & 1;
}
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }
template <class val>
const void maximize(val &a, val b)
{
    a = max(a, b);
}
template <class val>
const void minimize(val &a, val b)
{
    a = min(a, b);
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), m(0), neighborX[4] = {0, 0, 1, -1}, neighborY[4] = {1, -1, 0, 0}, path[1001][1001];
string guide("RLDU");
char f[1001][1001];

bool ok(int x, int y) { return x >= 1 && y >= 1 && x <= n && y <= m && f[x][y] != '#' && path[x][y] == -1; }
void bfs(ii start, ii end)
{
    queue<ii> q;
    q.push(start);
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        forup(int, i, 0, 3)
        {
            ii v = {u.fi + neighborX[i], u.se + neighborY[i]};
            if (!ok(v.fi, v.se))
                continue;
            path[v.fi][v.se] = i;
            q.push(v);
        }
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    ii start, end;
    cin >> n >> m;
    forup(int, i, 1, n) forup(int, j, 1, m)
    {
        cin >> f[i][j];
        if (f[i][j] == 'A')
            start = {i, j};
        if (f[i][j] == 'B')
            end = {i, j};
    }
    forup(int, i, 1, n) forup(int, j, 1, m) path[i][j] = -1;
    path[start.fi][start.se] = 4;
    bfs(start, end);
    if (path[end.fi][end.se] == -1)
        return cout << "NO", 0;
    vector<int> backTrack;
    while (end != start)
    {
        int cp(path[end.fi][end.se]);
        backTrack.pb(cp);
        end = {end.fi - neighborX[cp], end.se - neighborY[cp]};
    }
    cout << "YES" << '\n'
         << backTrack.size() << '\n';
    fordown(int, i, backTrack.size() - 1, 0) cout << guide[backTrack[i]];
    return 0;
}