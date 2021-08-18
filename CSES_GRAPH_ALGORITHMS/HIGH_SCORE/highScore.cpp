/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "highScore" //pls dont forget your task's name
#define maxn 2525
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
bool visited1[maxn * 2], visited2[maxn * 2];
vector<int> G1[maxn * 2], G2[maxn * 2];
vector<iii> edge;

void dfs1(int u)
{
    visited1[u] = 1;
    for (int v : G1[u])
        if (!visited1[v])
            dfs1(v);
}

void dfs2(int u)
{
    visited2[u] = 1;
    for (int v : G2[u])
        if (!visited2[v])
            dfs2(v);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0);
    ll u(0), v(0), w(0);
    cin >> n >> m;
    vector<ll> dis(n + 1, ll(1e16));
    while (m-- && cin >> u >> v >> w)
    {
        edge.pb({u, v, -w});
        G1[u].pb(v), G2[v].pb(u);
    }
    dfs1(1), dfs2(n);
    dis[1] = 0;
    forup(int, i, 1, n)
    {
        for (auto [a, b, c] : edge)
            if (dis[b] > dis[a] + c)
            {
                dis[b] = dis[a] + c;
                if (i == n && visited1[b] && visited2[b])
                    return cout << -1, 0;
            }
    }
    cout << -dis[n];
    return 0;
}