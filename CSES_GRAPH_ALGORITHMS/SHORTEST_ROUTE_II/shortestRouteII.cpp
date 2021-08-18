/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "shortestRouteII" //pls dont forget your task's name
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
ll dis[1001][1001];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    forup(int, i, 0, 1000) forup(int, j, 0, 1000) dis[i][j] = ll(1e13);
    int n(0), m(0), q(0);
    cin >> n >> m >> q;
    ll u(0), v(0), w(0);
    while (m-- && cin >> u >> v >> w)
    {
        dis[u][u] = dis[v][v] = 0;
        minimize(dis[u][v], w), minimize(dis[v][u], w);
    }
    forup(int, k, 0, n + 1) forup(int, i, 1, n) forup(int, j, 1, n) minimize(dis[i][j], dis[i][k] + dis[k][j]);
    int l(0), r(0);
    while (cin >> l >> r)
    {
        if (dis[l][r] < ll(1e13))
            cout << dis[l][r] << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}