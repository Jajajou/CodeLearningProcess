/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "clockwise" //pls dont forget your task's name
#define maxn 101001
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
char a[10][10];
int n(0);

void read()
{
    cin >> n;
    forup(i, 1, n)
    {
        forup(j, 1, n)
        {
            cin >> a[i][j];
        }
    }
    forup(i, 1, n)
    {
        forup(j, 1, n) cout << a[i][j];
        cout << endl;
    }
}

void solve()
{
    forup(i, 1, (n / 2))
    {
        forup(j, i, n - i)
        {
            char tmp(a[i][j]);
            a[i][j] = a[n - j + 1][i];
            a[n - j + 1][i] = a[n - i + 1][n - j + 1];
            a[n - i + 1][n - j + 1] = a[j][n - i + 1];
            a[j][n - i + 1] = tmp;
        }
    }
    cout << endl;
    forup(i, 1, n)
    {
        forup(j, 1, n) cout << a[i][j];
        cout << endl;
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}