/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "vsteps" //pls dont forget your task's name
#define maxn 14062008
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

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

void reset(int n, int f[], bool ok[])
{
    forup(int, i, 0, n) f[i] = ok[i] = 0;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), k(0);
    cin >> n >> k;
    int dp[n + 1];
    bool damagedStep[n + 1];
    reset(n, dp, damagedStep);
    for (int i(0), x(0); i < k and cin >> x; ++i)
        damagedStep[x] = 1;

    dp[1] = 1;
    forup(int, i, 2, n) dp[i] = (damagedStep[i]) ? 0 : (dp[i - 1] % maxn + dp[i - 2] % maxn) % maxn;
    cout << dp[n];
    return 0;
}