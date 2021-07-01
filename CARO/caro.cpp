/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "caro" //pls dont forget your task's name
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

void solve()
{
    char c;
    int x1(0), y1(0), x2(0), y2(0);
    cin >> c >> x1 >> y1 >> x2 >> y2;
    if ((x1 & 1) && (y1 & 1))
    {
        cout << "draw\n";
        return;
    }
    if (x1 == 2 && y1 == 2)
    {
        if ((x2 & 1) && (y2 & 1))
        {
            cout << "draw\n";
            return;
        }
        else
        {
            cout << c << endl;
            return;
        }
    }
    cout << "draw\n";
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}