/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tongtich" //pls dont forget your task's name
#define maxn 500005
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
using namespace std;
int n(0), checkPoint(4);
ll a[maxn] = {}, b[maxn] = {}, p(0);
map<ll, ll> f, g;

bool checkPrime(ll x)
{
    for (ll i = 2; i * i < x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return x > 1;
}

void read()
{
    cin >> n >> p;
}

void solve()
{
    ll res(0), cp1(0), cp2(0);
    if (p == 1000000000)
    {
        forup(i, 1, n)
        {
            cin >> a[i];
            ++f[a[i]];
        }
        res = (f[2] * (f[2] - 1)) / 2 + ((f[0] - 1) * f[0]) / 2;
    }
    else if (p <= 2000)
    {
        forup(i, 1, n)
        {
            cin >> a[i];
            a[i] %= p;
            ++f[a[i]];
        }
        forup(i, 0, p - 1) cout << i << ':' << f[i] << endl;
        forup(i, 0, p - 1)
        {
            forup(j, i, p - 1) if ((i + j) % p == (i * j) % p)
                res += f[i];
        }
    }
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