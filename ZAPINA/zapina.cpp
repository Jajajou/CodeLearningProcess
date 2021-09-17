/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "zapina" //pls dont forget your task's name
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

const ll MOD(1e9 + 7);
ll exp(ll a, ll b)
{
    if (!b)
        return 1;
    ll s(exp(a, b / 2));
    s *= s % MOD;
    if (b & 1)
        return ((s % MOD) * a) % MOD;
    else
        return (s % MOD);
}

void add(ll &a, const ll b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0)), C(n + 1, vector<ll>(n + 1, 0));
    C[0][0] = C[1][1] = C[1][0] = 1;
    forup(int, i, 2, n)
    {
        C[i][0] = C[i][i] = 1;
        forup(int, j, 1, i - 1)
        {
            add(C[i][j], C[i - 1][j - 1]);
            add(C[i][j], C[i - 1][j]);
        }
    }
    dp[0][0] = 1;
    forup(int, i, 1, n) forup(int, j, 0, n) forup(int, k, 0, j) if (i != k) add(dp[i][j], C[j][k] * dp[i - 1][j - k] % MOD);
    forup(int, i, 1, n) forup(int, j, 1, n) cout << dp[i][j] << " \n"[j == n];
    ll res(exp(n, n));
    add(res, MOD - dp[n][n]);
    cout << res;
    return 0;
}