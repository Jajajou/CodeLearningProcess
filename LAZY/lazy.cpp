/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "lazy" //pls dont forget your task's name
#define maxn 808
#define cut cout << endl
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), k(0);
ll f[maxn][maxn];

void read()
{
    cin >> n >> k;
    forup(i, 1, n) forup(j, 1, n)
    {
        cin >> f[i + j][n - i + j - 1];
    }
}

void solve()
{
    for (int i = max(0, i - k); i + k <= n; ++i)
    {
        for (int j = max(0, j - k); j + k <= n; ++j)
        {
        }
    }

    int main()
    {
        boost();
        IO();
        read();
        solve();
        return 0;
    }