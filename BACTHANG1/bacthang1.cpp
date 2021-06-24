/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "bacthang1" //pls dont forget your task's name
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
using namespace std;
short n(0);
map<short, long long> res;

void read()
{
    cin >> n;
    res[1] = 1;
    res[2] = 1;
}

void solve()
{
    forup(i, 3, n)
    {
        if (!res[i])
            res[i] = res[i - 1] + res[i - 2];
    }
    cout << res[n];
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}