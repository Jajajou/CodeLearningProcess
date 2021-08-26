/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "candies" //pls dont forget your task's name
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
const int MOD(int(1e9) + 7);
int n(0), k(0);
vector<int> candy;
vector<vector<int>> dp;

int sum(int a, int b)
{
    if ((a += b) > MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b)
{
    if ((a -= b) < 0)
        a += MOD;
    return a;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> k;
    candy.resize(n + 1, 0);
    forup(int, i, 1, n) cin >> candy[i];
    dp.resize(n + 1, vector<int>(k + 1, -1));
    dp[0][0] = 1;
    forup(int, i, 1, k) dp[0][i] = 0;
    forup(int, i, 1, n) dp[i][0] = 1;
    forup(int, cand, 1, n)
    {
        vector<int> pref(k + 1, 0);
        pref[0] = dp[cand - 1][0];
        forup(int, i, 1, k) pref[i] = sum(pref[i - 1], dp[cand - 1][i]);
        forup(int, i, 0, k) if (i <= candy[cand]) dp[cand][i] = pref[i];
        else dp[cand][i] = sub(pref[i], pref[i - candy[cand] - 1]);
        pref.clear();
    }
    cout << dp[n][k];
    return 0;
}