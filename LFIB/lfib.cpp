/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "lfib" //pls dont forget your task's name
#define maxn 101001
#define pri_q priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin
template <class val>
val mul(val a, val b, val mod)
{
    if (!b)
        return 0;
    if (!(b - 1))
        return a;
    return b & 1 ? (mul(a, b >> 1, mod) * 2 + a) % mod : (mul(a, b >> 1, mod) * 2) % mod;
}
typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
struct matrix
{
    ll res[3][3];

    matrix()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                res[i][j] = 0LL;
        for (int i = 0; i < 3; ++i)
            res[1][i] = 1LL;
        res[0][1] = res[2][2] = 1LL;
    }

    matrix(ll tmp[][3])
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                res[i][j] = tmp[i][j];
    }

    matrix operator%(const ll &k)
    {
        ll tmp[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[i][j] = res[i][j] % k;
        return matrix(tmp);
    }
};
ll a(0), b(0), n(0), k(0), mod(0);

matrix operator*(matrix a, matrix b)
{
    ll res[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            res[i][j] = [&]()
            {
                ll cp(0);
                for (int k = 0; k < 3; ++k)
                    cp = ((cp % mod) + (mul(a.res[i][k] % mod, b.res[k][j] % mod, mod) % mod) % mod);
                return cp;
            }();
    }
    return matrix(res) % mod;
}

matrix operator^(matrix A, ll n)
{
    if (n <= 1)
        return A % mod;
    matrix res = A ^ (n >> 1);
    return n & 1 ? ((res % mod) * (res % mod) * (A % mod)) % mod : (res % mod) * (res % mod);
}

ll lfib(int n)
{
    if (n && n < 3)
        return n == 1 ? a % mod : b % mod;
    matrix ans = matrix() ^ (n - 1);
    return ((mul(ans.res[0][0] % mod, a % mod, mod) % mod) + (mul(ans.res[0][1] % mod, b % mod, mod) % mod) + (ans.res[0][2] % mod)) % mod;
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
        cin >> a >> b >> n >> k >> mod;
        ll res(((lfib(n + 2) % mod) - (lfib(2) % mod) - (n % mod) + (mod << 1)) % mod);
        cout << (((k == 1) ? res % mod : ((((a % mod) * (a % mod)) % mod) + (((lfib(n) % mod) * (lfib(n + 1) % mod)) % mod) - ((a % mod) * (b % mod)) - (res % mod) + (a % mod) + mod * mod) % mod)) << "\n";
    }
    return 0;
}