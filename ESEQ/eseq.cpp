/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "eseq" //pls dont forget your task's name
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

int main()
{
    boost();
    IO();
    int n(0), x(0);
    cin >> n;
    vector<ll> f(n + 1);
    map<ll, ll> m;
    for (int i(1); i <= n and cin >> x; ++i)
    {
        f[i] = f[i - 1] + x;
    }
    int tmp(f[n]);
    ll res(0);
    forup(i, 1, n)
    {
        cout << f[i] << ' ' << tmp - f[i - 1] << endl;
        res += m[tmp - f[i - 1]];
        ++m[f[i]];
    }
    cout << res;
    return 0;
}