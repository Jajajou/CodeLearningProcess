/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "countingNumbers" //pls dont forget your task's name
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
val getBit(val x, val pos)
{
    return x >> pos & 1;
}
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
    Fin(name);
    Fout(name);
}
ll dp[25][11][2][2];
ll cal(string &s, int n, int digit, bool preZero, bool tight)
{
    if (n == 0)
        return 1;
    if (digit != -1 && dp[n][digit][preZero][tight] != -1)
        return dp[n][digit][preZero][tight];
    int m(tight ? s[s.size() - n] - '0' : 9);
    ll res(0);
    forup(int, i, 0, m) if (i == digit && (!preZero)) continue;
    else res += cal(s, n - 1, i, preZero & (i == 0), tight & (i == m));
    return dp[n][digit][preZero][tight] = res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    string a, b;
    ll x, y;
    cin >> x >> y;
    a = to_string(x - 1);
    b = to_string(y);
    memset(dp, -1, sizeof(dp));
    ll r(cal(b, b.size(), -1, 1, 1));
    memset(dp, -1, sizeof(dp));
    ll l(cal(a, a.size(), -1, 1, 1));
    cout << r - l;
    return 0;
}