/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "vsteps" //pls dont forget your task's name
#define maxn 101001
#define mod 14062008
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
unsigned int n(0), k(0);
map<unsigned int, bool> check;
map<unsigned int, unsigned ll> f;

void read()
{
    cin >> n >> k;
    unsigned int x(0);
    forup(i, 1, k)
    {
        cin >> x;
        check[x] = 1;
    }
    f[1] = 1;
    if (check[2])
        f[2] = 0;
    else
        f[2] = 1;
}

void solve()
{
    forup(i, 3, n)
    {
        if (!check[i])
            f[i] = (f[i - 1] % mod + f[i - 2] % mod) % mod;
        else
            f[i] = 0;
    }
    cout << f[n];
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}