/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "select" //pls dont forget your task's name
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
val getBit(val x, val pos) { return x >> (pos - 1) & 1; }
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << (pos - 1)) : inp &= ~(1 << (pos - 1)); }

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0);
ll **a(NULL);
ll *dp(NULL);

void read()
{
    cin >> n;
    a = new ll *[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = new ll[n];
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    dp = new ll[1 << n];
    for (int state(0); state < 1 << n; ++state)
        dp[state] = 0;
}

void solve()
{
    for (int state = 1; state < (1 << n); ++state)
    {
        int row(__builtin_popcount(state) - 1);
        for (int i = 0; i < n; ++i)
            if (getBit(state, i + 1))
                dp[state] = max(dp[state], dp[state ^ (1 << i)] + a[row][i]);
    }
    cout << dp[(1 << n) - 1];
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    for (int i = 0; i < n; ++i)
        delete[] a[i];
    delete[] a;
    delete[] dp;
    return 0;
}