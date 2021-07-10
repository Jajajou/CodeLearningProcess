/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "nktick" //pls dont forget your task's name
#define maxn 60000
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
int n(0);
int *ar, *arr, *dp;

void read()
{
    cin >> n;
    ar = new int[n + 1];
    arr = new int[n + 2];
    forup(int, i, 1, n) cin >> ar[i];
    forup(int, i, 2, n) cin >> arr[i];
}

void solve()
{
    dp = new int[n + 1];
    dp[0] = 0, dp[1] = ar[1];
    forup(int, i, 2, n) dp[i] = min(ar[i] + dp[i - 1], arr[i] + dp[i - 2]);
    cout << dp[n];
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    delete[] dp, ar, arr;
    return 0;
}