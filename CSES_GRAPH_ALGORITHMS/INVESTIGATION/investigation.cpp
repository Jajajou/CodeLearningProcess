/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "investigation" //pls dont forget your task's name
#define maxn int(2e5) + 25
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
typedef pair<ll, int> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
const ll MOD(ll(1e9) + 7LL);
bool visited[maxn];
int n(0), m(0), u(0), v(0);
ll w(0);
vector<ii> G[maxn], cost;
vector<int> dpMin, dpMax;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    dpMin.resize(n + 1, int(1e9));
    dpMax.resize(n + 1, 0);
    cost.resize(n + 1, {ll(1e16), 0});
    dpMin[1] = dpMax[1] = 0;
    cost[1] = {0LL, 1};
    set<ii> q;
    forup(int, i, 1, n)
        q.emplace(cost[i].fi, i);
    while (cin >> u >> v >> w)
        G[u].pb({w, v});
    while (!q.empty())
    {
        ii u(*q.begin());
        q.erase(q.begin());
        visited[u.se] = 1;
        for (ii v : G[u.se])
        {
            if (visited[v.se])
                continue;
            if (cost[v.se].fi > cost[u.se].fi + v.fi)
            {
                q.erase(q.find({cost[v.se].fi, v.se}));
                q.emplace(cost[v.se].fi = cost[u.se].fi + v.fi, v.se);
                cost[v.se].se = cost[u.se].se;
                dpMin[v.se] = dpMin[u.se] + 1;
                dpMax[v.se] = dpMax[u.se] + 1;
            }
            elif (cost[v.se].fi == cost[u.se].fi + v.fi)
            {
                (cost[v.se].se += cost[u.se].se) %= MOD;
                minimize(dpMin[v.se], dpMin[u.se] + 1);
                maximize(dpMax[v.se], dpMax[u.se] + 1);
            }
        }
    }
    cout << cost[n].fi << ' ' << cost[n].se << ' ' << dpMin[n] << ' ' << dpMax[n];
    return 0;
}