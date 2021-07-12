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

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

class matrixMul
{
public:
    int a, b, n, k, mod;
    // ll arr[3][3], base[3][1];

    // matrixMul()
    // {
    //     for (int i(0); i < 3; ++i)
    //         arr[0][i] = 1;
    //     for (int i(1); i < 3; ++i)
    //         arr[i][i - 1] = 1;
    // }

    // matrixMul(int tmp[][3])
    // {
    //     forup(int, i, 0, 2) forup(int, j, 0, 2) arr[i][j] = tmp[i][j];
    // }

    // matrixMul operator*(const matrixMul &m)
    // {
    //     int res[3][3];
    //     for (int i = 0; i < 3; ++i)
    //     {
    //         for (int j = 0; j < 3; ++j)
    //             res[i][j] = [&]()
    //             {
    //                 ll cp(0);
    //                 for (int k = 0; k < 3; ++k)
    //                     cp = ((cp % mod) + ((arr[i][k] % mod) * (m.arr[k][j] % mod) % mod)) % mod;
    //                 return cp;
    //             }();
    //     }
    //     return matrixMul(res);
    // }

    // matrixMul operator^=(const ll &n)
    // {
    //     if (n <= 1)
    //         return matrixMul();
    //     matrixMul res = *this ^= (n >> 1);
    //     return n & 1 ? res * res * matrixMul() : res * res;
    // }

    // ll lfib(int n)
    // {
    //     if (n < 3 && n)
    //         return n == 1 ? a % mod : b % mod;
    //     int x = (matrixMul() ^= (n - 1)).arr[0][0], y = (matrixMul() ^= (n - 1)).arr[0][1], z = (matrixMul() ^= (n - 1)).arr[0][2];
    //     return (((x % mod) * (base[0][0] % mod) % mod) + ((y % mod) * (base[1][0] % mod) % mod) + ((z % mod) * (base[2][0] % mod) % mod) % mod);
    // }

    void solve()
    {
        cin >> a >> b >> n >> k >> mod;
        cout << k << endl;
        // base[0][0] = a % mod, base[0][1] = b % mod, base[0][2] = 1;
        // ll res(((lfib(n + 2) % mod) - (lfib(2) % mod) - n % mod + mod * mod) % mod);
        // if (k == 1)
        //     return (void)(cout << res << endl);
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    while (t--)
        matrixMul().solve();
    return 0;
}