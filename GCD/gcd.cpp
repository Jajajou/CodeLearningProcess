/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "gcd" //pls dont forget your task's name
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

ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main()
{
    boost();
    IO();
    ll n(0), res(0);
    cin >> n;

    vector<ll> a(n + 1), l(n + 1, 0), r(n + 2, 0);
    forup(i, 1, n) cin >> a[i];
    forup(i, 1, n)
    {
        l[i] = gcd(l[i - 1], a[i]);
        r[n - i + 1] = gcd(r[n - i + 2], a[n - i + 1]);
    }
    forup(i, 1, n) res = max(res, gcd(l[i - 1], r[i + 1]));
    cout << res;
    return 0;
}