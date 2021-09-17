/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "qbgame" //pls dont forget your task's name
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
vector<vector<ll>> dp, ar;

bool verticalCheck(int mask)
{
    forup(int, i, 1, 7) if (getBit(mask, i) && getBit(mask, i - 1)) return 0;
    return 1;
}

bool horizontalCheck(int mask1, int mask2)
{
    return (mask1 & mask2) == 0;
}

ll sumState(int j, int mask)
{
    ll res(0);
    forup(int, i, 0, 7) if (getBit(mask, i)) res += ar[i][j];
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    ll mx(-ll(1e16));
    cin >> n;
    ar.resize(8, vector<ll>(n));
    forup(int, i, 0, 7) forup(int, j, 0, n - 1) cin >> ar[i][j], maximize(mx, ar[i][j]);
    if (mx < 0)
        return cout << mx, 0;
    vector<int> state;
    forup(int, mask, 0, (1 << 8) - 1)
    {
        bool ok(1);
        for (int i(1); i < 8 && ok; ++i)
            ok = (mask & 3 << i) != (3 << i);
        if (ok)
            state.pb(mask);
    }
    dp.resize(n, vector<ll>((1 << 8), 0));
    for (int mask : state)
        dp[0][mask] = sumState(0, mask);

    forup(int, i, 1, n - 1) for (int mask1 : state) if (verticalCheck(mask1))
    {
        ll maxVal(-ll(1e16));
        for (int mask2 : state)
            if (verticalCheck(mask2) && horizontalCheck(mask1, mask2))
                maximize(maxVal, dp[i - 1][mask2]);
        dp[i][mask1] = sumState(i, mask1) + maxVal;
    }
    ll res(-ll(1e16));
    for (int mask : state)
        maximize(res, dp[n - 1][mask]);
    cout << res;
    return 0;
}