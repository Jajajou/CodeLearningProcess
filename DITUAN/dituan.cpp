/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "dituan" // pls dont forget your task's name
#define maxn 101001
#define elif else if
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
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
const int dX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dY[8] = {1, -1, 2, 2, 1, -1, -2, -2};
int n(0), m(0), matrix[22][22], res(INT_MAX);
bool visited[22][22];

bool check(int x, int y) { return (x > 0 && y > 0 && x <= n && y <= m); }

void dfs(int u, int v, int sum, int move)
{
    visited[u][v] = 1;
    forup(int, k, 0, 7)
    {
        if (move == n * m)
            minimize(res, sum);
        if (check(u + dX[k], v + dY[k]) && !visited[u + dX[k]][v + dY[k]])
            dfs(u + dX[k], v + dY[k], sum + (move * matrix[u + dX[k]][v + dY[k]]), move + 1);
    }
    visited[u][v] = 0;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    forup(int, i, 1, n) forup(int, j, 1, m) cin >> matrix[i][j];
    dfs(1, 1, 0, 1);
    if (res == INT_MAX)
        cout << -1;
    else
        cout << res;
    return 0;
}