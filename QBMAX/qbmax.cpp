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
#define o(i, j) (i <= m && j <= n && i > 0 && j > 0 ? dp[i][j] : INT_MIN)

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int arr[105][105], dp[105][105];

void reset()
{
    forup(int, i, 0, 104) forup(int, j, 0, 104) arr[i][j] = dp[i][j] = 0;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    reset();
    int n(0), m(0);
    cin >> m >> n;

    forup(int, i, 1, m) forup(int, j, 1, n) cin >> arr[i][j];
    forup(int, i, 1, m) dp[i][1] = arr[i][1];
    forup(int, j, 2, n) dp[1][j] = arr[1][j] + dp[1][j - 1];
    forup(int, j, 2, n) forup(int, i, 2, m)
        dp[i][j] = arr[i][j] + max({o(i, j - 1), o(i - 1, j - 1), o(i + 1, j - 1)});
    cout << [&]()
    {
        int res(INT_MIN);
        forup(int, i, 1, m) res = max(res, dp[i][n]);
        return res;
    }();
    return 0;
}