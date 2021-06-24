/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "vcowflix" //pls dont forget your task's name
#define maxn 101001
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
int c(0), n(0), a[maxn] = {}, b[maxn] = {}, f[maxn] = {}, res(INT_MIN);

void read()
{
    cin >> c >> n;
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
            if (f[x] == c)
            {
                cout << c;
                exit(0);
            }
            else if (f[x] < c)
            {
                res = max(res, f[x]);
                solve(x + 1);
            }
        }
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(1);
    cout << res;
}