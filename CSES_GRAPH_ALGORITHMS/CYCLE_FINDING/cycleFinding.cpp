/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "cycleFinding" //pls dont forget your task's name
#define maxn 5005
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
typedef tuple<int, int, ll> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
vector<iii> edge;
vector<ll> dis, path;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0), u(0), v(0);
    ll w(0);
    cin >> n >> m;
    while (cin >> u >> v >> w)
        edge.pb({u, v, w});
    dis.resize(n + 1, ll(1e15));
    path.resize(n + 1, 0);
    int f(0);
    forup(int, i, 1, n)
    {
        f = 0;
        for (auto [u, v, w] : edge)
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                path[v] = u;
                f = v;
            }
        }
    }
    if (!f)
        return cout << "NO", 0;
    forup(int, i, 1, n) f = path[f];
    cout << "YES\n";
    vector<int> res;
    int c(f);
    res.pb(f);
    do
    {
        f = path[f];
        res.pb(f);
    } while (f - c);
    reverse(res.begin(), res.end());
    for (int v : res)
        cout << v << ' ';
    return 0;
}