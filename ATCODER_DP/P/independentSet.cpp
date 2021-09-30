/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "independentSet" //pls dont forget your task's name
#define maxn int(1e5) + 15
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
const ll MOD = 1e9 + 7;
int n(0);
vector<int> adj[maxn];
vector<vector<ll>> dp;

ll DP(int u, int color, int cp)
{
    if (dp[u][color] != -1)
        return dp[u][color];
    ll &res = dp[u][color] = 1LL;
    for (int v : adj[u])
    {
        if (v == cp)
            continue;
        if (color)
            (res *= DP(v, 0, u)) %= MOD;
        else
            (res *= (DP(v, 0, u) + DP(v, 1, u))) %= MOD;
    }
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    dp.resize(n + 1, vector<ll>(2, -1));
    for (int i(1), u, v; i < n && cin >> u >> v; ++i)
        adj[u].pb(v), adj[v].pb(u);
    cout << (DP(1, 0, -1) + DP(1, 1, -1)) % MOD;
    return 0;
}