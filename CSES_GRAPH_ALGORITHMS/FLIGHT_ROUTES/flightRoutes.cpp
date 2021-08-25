/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "flightRoutes" //pls dont forget your task's name
#define maxn int(2e5) + 25
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
vector<ii> G[maxn];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0), k(0), u(0), v(0);
    ll w(0);
    cin >> n >> m >> k;
    while (cin >> u >> v >> w)
        G[u].pb({w, v});
    pri_q<ii, vector<ii>, greater<ii>> q;
    vector<int> cnt(n + 1, 0);
    q.emplace(0, 1);
    int cp(k);
    while (!q.empty())
    {
        ii u(q.top());
        q.pop();
        if (++cnt[u.se] > k)
            continue;
        if (u.se == n)
        {
            --cp, cout << u.fi << ' ';
            if (!cp)
                return 0;
        }
        for (ii v : G[u.se])
            if (cnt[v.se] <= k)
                q.emplace(u.fi + v.fi, v.se);
    }
    return 0;
}