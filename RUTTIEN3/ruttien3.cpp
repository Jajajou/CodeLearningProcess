/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ruttien3" //pls dont forget your task's name
#define maxn 10001
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
int n(0), m(0), a[maxn] = {}, b[maxn] = {}, f[maxn] = {}, res(0);

void read()
{
    cin >> m >> n;
    forup(i, 1, n) cin >> a[i];
}

void solve(int x)
{
    forup(i, 1, n)
    {
        if (b[x - 1] < i)
        {
            b[x] = i;
            f[x] = f[x - 1] + a[i];
            if (f[x] == m)
                ++res;
            else if (f[x] < m)
                solve(x + 1);
        }
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    /* read();
    solve(1);
    cout << res; */
    int n(0), target(0);
    cin >> target >> n;
    vector<int> c(n);
    for (int &v : c)
        cin >> v;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    forup(i, 1, n) forup(j, 0, target)
    {
        dp[i][j] = dp[i - 1][j];
        if (j - c[i - 1] >= 0 && dp[i - 1][j - c[i - 1]])
            dp[i][j] += dp[i - 1][j - c[i - 1]];
    }
    cout << dp[n][target];
}