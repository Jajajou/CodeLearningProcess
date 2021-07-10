/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "qbmax" //pls dont forget your task's name
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
#define o(j, i) (i <= m && j <= n && i > 0 && j > 0 ? dp[j][i] : INT_MIN)

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int arr[105][105], dp[105][105];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0);
    cin >> m >> n;

    forup(int, i, 1, m) forup(int, j, 1, n) cin >> arr[i][j];
    forup(int, i, 1, m) dp[1][i] = arr[i][1];

    forup(int, j, 2, n) forup(int, i, 1, m)
        dp[j][i] = arr[i][j] + max({o(j - 1, i), o(j - 1, i + 1), o(j - 1, i - 1)});
    cout << [&]()
    {
        int res(INT_MIN);
        forup(int, i, 1, m) res = max(res, dp[n][i]);
        return res;
    }();
    return 0;
}