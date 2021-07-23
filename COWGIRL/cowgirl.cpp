/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "cowgirl" //pls dont forget your task's name
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
val getBit(val x, val pos) { return x >> pos & 1; }
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

void solve()
{
    int n(0), m(0);
    cin >> n >> m;
    if (m < n)
        swap(m, n);
    ll dp[m][1 << n], res(0);

    function<bool(int, int)> check = [&](int sta1, int sta2)
    {
        forup(int, i, 1, n - 1) if (getBit(sta1, i) == getBit(sta1, i - 1) && getBit(sta1, i - 1) == getBit(sta2, i) && getBit(sta2, i) == getBit(sta2, i - 1)) return 0;
        return 1;
    };

    forup(int, i, 0, m - 1) forup(int, state, 0, (1 << n) - 1) dp[i][state] = 0;
    forup(int, state, 0, (1 << n) - 1) dp[0][state] = 1;

    forup(int, i, 1, m - 1) forup(int, state1, 0, (1 << n) - 1) forup(int, state2, 0, (1 << n) - 1)
    {
        if (check(state1, state2))
            dp[i][state1] += dp[i - 1][state2];
    }

    forup(int, state, 0, (1 << n) - 1) res += dp[m - 1][state];
    cout << res << endl;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}