/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "c11water" //pls dont forget your task's name
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

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0), moveX[4] = {-1, 0, 1, 0}, moveY[4] = {0, 1, 0, -1};
    cin >> n >> m;
    vector<vector<int>> h(n + 1, vector<int>(m + 1, 0)), f(n + 1, vector<int>(m + 1, INT_MAX));
    pri_q<iii, vector<iii>, greater<iii>> q;
    forup(int, i, 1, n) forup(int, j, 1, m) cin >> h[i][j];
    forup(int, i, 1, n)
    {
        f[i][1] = h[i][1];
        f[i][m] = h[i][m];
        q.emplace(f[i][1], i, 1);
        q.emplace(f[i][m], i, m);
    }
    forup(int, j, 1, m)
    {
        f[1][j] = h[1][j];
        f[n][j] = h[n][j];
        q.emplace(f[1][j], 1, j);
        q.emplace(f[n][j], n, j);
    }
    ll res(0);
    while (!q.empty())
    {
        auto [w, u, v] = q.top();
        q.pop();
        forup(int, i, 0, 3)
        {
            int x(u + moveX[i]), y(v + moveY[i]);
            if (x < 1 || y < 1 || x > n || y > m)
                continue;
            if (f[x][y] > max(f[u][v], h[x][y]))
            {
                f[x][y] = max(f[u][v], h[x][y]);
                q.emplace(f[x][y], x, y);
            }
        }
    }
    forup(int, i, 1, n) forup(int, j, 1, m) res += f[i][j] - h[i][j];
    cout << res;
    return 0;
}