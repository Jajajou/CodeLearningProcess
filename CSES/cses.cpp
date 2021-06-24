/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "cses" //pls dont forget your task's name
#define maxn 101001
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
ll f[1001][1001];

int main()
{

    boost();
    // IO();
    int n(0), q(0);
    cin >> n >> q;

    char c(' ');
    forup(i, 1, n) forup(j, 1, n)
    {
        cin >> c;
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (c == '*');
    }

    int x1(0), y1(0), x2(0), y2(0);
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}