/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "countingRoom" //pls dont forget your task's name
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
int n(0), m(0), neighborX[4] = {0, 0, 1, -1}, neighborY[4] = {1, -1, 0, 0};
char f[1001][1001];
bool visited[1001][1001];

bool ok(int x, int y) { return x >= 1 && y >= 1 && x <= n && y <= m && f[x][y] != '#'; }
void dfs(int x, int y)
{
    visited[x][y] = 1;
    forup(int, k, 0, 3)
    {
        if (ok(x + neighborX[k], y + neighborY[k]) && !visited[x + neighborX[k]][y + neighborY[k]])
            dfs(x + neighborX[k], y + neighborY[k]);
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    forup(int, i, 1, n) forup(int, j, 1, m) cin >> f[i][j];
    int res(0);
    forup(int, i, 1, n) forup(int, j, 1, m)
    {
        if (f[i][j] == '.' && !visited[i][j])
            ++res, dfs(i, j);
    }
    cout << res;
    return 0;
}