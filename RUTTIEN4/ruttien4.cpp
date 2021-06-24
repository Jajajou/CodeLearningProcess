/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ruttien4" //pls dont forget your task's name
#define maxn 101
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
int n(0), m(0), a[maxn] = {}, res(0), cp(0);
bool check[1001] = {};

void read()
{
    cin >> n >> m;
    forup(i, 1, n) cin >> a[i];
}

void solve(int x)
{
    forup(i, 1, n)
    {
        if (!check[i])
        {
            check[i] = !check[i];
            cp += a[i];
            if (cp == m)
                ++res;
            else if (cp < m)
                solve(x + 1);
            check[i] = !check[i];
            cp -= a[i];
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