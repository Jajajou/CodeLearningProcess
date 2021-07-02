/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "xephinh" //pls dont forget your task's name
#define maxn 101001
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

ull tt(ull a, ull b, ull h) { return a * b * h; }

ull cv(ull a, ull b, ull h) { return 4 * (a + b + h); }

ull dt(ull a, ull b, ull h) { return 2 * a * b + 2 * h * (a + b); }

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
        ull a(0), b(0), h(0);
        cin >> a >> b >> h;
        cout << tt(a, b, h) << ' ' << cv(a, b, h) << ' ' << dt(a, b, h) << "\n";
    }
    return 0;
}