/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "or" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
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
// #define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
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
const int MOD = 1e9 + 7;
int dp[256][256][256];
int n(0), k(0), l(0), r(0);

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> k >> l >> r;
    vector<int> ar(n + 1, 0);
    forup(int, i, 1, n) cin >> ar[i];
    if (n <= 20)
    {
        int res(0);
        forup(int, mask, 0, (1 << n) - 1)
        {
            if (__builtin_popcount(mask) != k)
                continue;
            int v(0);
            forup(int, i, 0, n - 1) if (getBit(mask, i)) v |= ar[i + 1];
            res += ((v >= l) && (v <= r) && (v % 3 == 0));
        }
        cout << res;
    }
    elif (n <= 200)
    {
        memset(dp, 0, sizeof(dp));
        forup(int, i, 1, n) dp[1][ar[i]][i] = 1;
        forup(int, i, 1, k) forup(int, j, 1, n - 1) forup(int, v, 0, 255)
        {
            (dp[i + 1][v | ar[j + 1]][j + 1] += dp[i][v][j]) %= MOD;
            (dp[i][v][j + 1] += dp[i][v][j]) %= MOD;
        }
        int res(0);
        forup(int, i, l, r) if (i % 3 == 0)(res += dp[k][i][n]) %= MOD;
        cout << res;
    }
    return 0;
}