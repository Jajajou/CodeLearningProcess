/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "sum1007" //pls dont forget your task's name
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
int n(0);
map<int, int> f;

void read()
{
    int x(0);
    cin >> n;
    forup(i, 1, n)
    {
        forupIn(j, 1, n, x)
        {
            f[i - j] += x;
        }
    }
}

void solve()
{
    int res(INT_MIN);
    forup(i, -n, n) res = max(res, f[i]);
    cout << res;
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}