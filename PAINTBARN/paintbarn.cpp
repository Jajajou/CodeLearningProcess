/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "paintbarn" //pls dont forget your task's name
#define maxn int(1e3) + 13
#define cut cout << endl
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".in", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

int main()
{
    boost();
    IO();
    int n(0), k(0), m(0);
    cin >> n >> k;

    ll f[maxn][maxn];
    int x1(0), y1(0), x2(0), y2(0);
    forup(i, 1, n)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        m = max(x1, max(x2, max(y1, y2)));
        ++f[x1][y1], ++f[x2][y2];
        --f[x1][y2], --f[x2][y1];
    }

    int res(0);
    forup(i, 1, m) forup(j, 1, m)
    {
        f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        res += (f[i][j] == k);
    }
    cout << res;

    return 0;
}