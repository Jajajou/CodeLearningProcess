/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "cado" //pls dont forget your task's name
#define maxn int(1e9) + 7
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)

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
    int n(0), k(0);
    cin >> n >> k;

    int f[n + 1][k + 1] = {{0}}, a[n + 1] = {}, s[n + 1] = {};
    forup(i, 1, n)
    {
        cin >> a[i];
        f[i][1] = a[i];
        s[i] = s[i - 1] + f[i][1];
    }
    forup(j, 2, k) forup(i, 1, n)
    {
        f[i][j] = a[i] * (s[n] - s[i]);
        s[i] = s[i - 1] + f[i][j];
    }

    int res(0);
    forup(i, 1, n) res += f[i][k];
    cout << res << endl;

    return 0;
}