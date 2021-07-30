/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "nkpalin" //pls dont forget your task's name
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

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    string s("");
    cin >> s;
    int n(s.size());
    s = " " + s;
    int dp[n + 1][n + 1];
    forup(int, i, 0, n) forup(int, j, 0, n) dp[i][j] = 0;
    forup(int, i, 1, n) fordown(int, j, n, 1) if (s[i] == s[j]) dp[i][n - j + 1] = dp[i - 1][n - j] + 1;
    else dp[i][n - j + 1] = max(dp[i - 1][n - j + 1], dp[i][n - j]);
    int m(n);
    string res("");
    while (dp[n][m])
    {
        if (s[n] == s[s.size() - m])
            res += s[n], --m, --n;
        else if (dp[n][m] == dp[n - 1][m])
            --n;
        else
            --m;
    }
    cout << res;
    return 0;
}