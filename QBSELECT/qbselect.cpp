/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "qbselect" //pls dont forget your task's name
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
ll **a, **dp;

void read()
{
    cin >> n;
    a = new ll *[5];
    dp = new ll *[n + 1];
    for (int i(0); i <= n; ++i)
        dp[i] = new ll[(1 << 4) + 1];
    for (int i = 1; i <= 4; ++i)
    {
        a[i] = new ll[n + 1];
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i(0); i <= n; ++i)
    {
        for (int state(0); state <= 16; ++state)
            dp[i][state] = 0;
    }
}

bool vCheck(int state)
{
    forup(int, k, 2, 4) if (getBit(state, k) && getBit(state, k - 1)) return 0;
    return 1;
}

bool hCheck(int x, int y)
{
    forup(int, k, 1, 4) if (getBit(x, k) && getBit(y, k)) return 0;
    return 1;
}

ll sum(int col, int state)
{
    ll s(0);
    forup(int, k, 1, 4) if (getBit(state, k)) s += a[k][col];
    return s;
}

void solve()
{
    for (int i(1); i <= n; ++i)
    {
        for (int state1(0); state1 <= (1 << 4); ++state1)
            if (vCheck(state1))
            {
                ll maxVal(LONG_MIN);
                for (int state2(1); state2 <= (1 << 4); ++state2)
                    if (vCheck(state2) && hCheck(state1, state2))
                        maxVal = max(maxVal, dp[i - 1][state2]);
                dp[i][state1] = maxVal + sum(i, state1);
            }
    }
    ll res(LONG_MIN);
    for (int state(0); state <= 16; ++state)
        res = max(res, dp[n][state]);
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    for (int i = 1; i <= 4; ++i)
        delete[] a[i];
    delete[] a;
    for (int i = 1; i <= n; ++i)
        delete[] dp[i];
    delete[] dp;
    return 0;
}