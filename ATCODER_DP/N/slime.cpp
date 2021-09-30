/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "slime" //pls dont forget your task's name
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
int n(0);
vector<ll> ar, pref;
vector<vector<ll>> dp;

ll sum(int a, int b) { return a > b ? int(1e9) : pref[b] - pref[a - 1]; }

ll DP(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
        return dp[l][r] = 0LL;
    if (l + 1 == r)
        return dp[l][r] = ar[l] + ar[r];
    ll &res = dp[l][r] = ll(1e18), s(sum(l, r));
    forup(int, i, l, r - 1) minimize(res, DP(l, i) + DP(i + 1, r) + s);
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    ar.resize(n + 1, 0);
    pref.resize(n + 1, 0);
    forup(int, i, 1, n) cin >> ar[i];
    forup(int, i, 1, n) pref[i] = pref[i - 1] + ar[i];
    dp.resize(n + 1, vector<ll>(n + 1, -1));
    cout << DP(1, n);
    return 0;
}