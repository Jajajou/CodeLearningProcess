/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "digitSum" //pls dont forget your task's name
#define maxn int(1e4) + 14
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
string k;
int d;
ll dp[int(1e4) + 14][int(1e2) + 12][2];

ll DP(int pos, int modc, int flag)
{
    if (pos == k.size())
        return modc == 0;
    if (dp[pos][modc][flag] != -1)
        return dp[pos][modc][flag];
    int limit(flag ? k[pos] - '0' : 9);
    ll &res = dp[pos][modc][flag] = 0;
    forup(int, i, 0, limit)(res += DP(pos + 1, (modc + i) % d, flag && (i == limit))) %= MOD;
    return res % MOD;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> k;
    cin >> d;
    memset(dp, -1, sizeof(dp));
    cout << (DP(0, 0, 1) - 1 + MOD) % MOD;
    return 0;
}