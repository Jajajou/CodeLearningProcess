/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "one4ever" //pls dont forget your task's name
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
ull a, b, mod, k;

class matrixMul
{
public:
    ull res[2][2];

    matrixMul() { res[0][0] = a % mod, res[0][1] = res[1][1] = 1 % mod, res[1][0] = 0; }

    matrixMul(ull a, ull b, ull c, ull d) { res[0][0] = a, res[0][1] = b, res[1][0] = c, res[1][1] = d; }

    matrixMul operator%(const ull &k) { return matrixMul(res[0][0] % k, res[0][1] % k, res[1][0] % k, res[1][1] % k); }

    ull mul(ull x, ull y)
    {
        if (x == 0 || y == 0)
            return 0;
        string X = "", Y = "";
        for (; x > 0; x /= 10)
            X += char(x % 10 + '0');
        for (; y > 0; y /= 10)
            Y += char(y % 10 + '0');
        string Z(X.size() + Y.size(), '0');
        for (int i = 0; i < (int)X.size(); i++)
        {
            int c = 0;
            for (int j = 0; j < (int)Y.size(); j++)
            {
                int g = Z[i + j] - '0' + c + (X[i] - '0') * (Y[j] - '0');
                c = g / 10;
                g %= 10;
                Z[i + j] = char(g + '0');
            }
            if (c > 0)
                Z[i + Y.size()] = char(Z[i + Y.size()] - '0' + c + '0');
        }
        ull ans = 0;
        for (int i = (int)Z.size() - 1; i >= 0; i--)
            ans = (ans * 10ull + Z[i] - '0') % mod;
        return ans;
    }

    matrixMul operator*(const matrixMul &m)
    {
        return matrixMul(((mul(res[0][0] % mod, m.res[0][0] % mod)) % mod) + ((mul(res[0][1] % mod, m.res[1][0] % mod)) % mod),
                         ((mul(res[0][0] % mod, m.res[0][1] % mod)) % mod) + ((mul(res[0][1] % mod, m.res[1][1] % mod)) % mod),
                         ((mul(res[1][0] % mod, m.res[0][0] % mod)) % mod) + ((mul(res[1][1] % mod, m.res[1][0] % mod)) % mod),
                         ((mul(res[1][0] % mod, m.res[0][1] % mod)) % mod) + ((mul(res[1][1] % mod, m.res[1][1] % mod)) % mod)) %
               mod;
    }

    matrixMul operator^=(const ull &n)
    {
        if (n <= 1)
            return matrixMul();
        matrixMul res = *this ^= (n >> 1);
        return n & 1 ? res * res * matrixMul() : res * res % mod;
    }

    ull solve()
    {
        ull A((matrixMul() ^= (k - 1)).res[0][0]), B((matrixMul() ^= (k - 1)).res[0][1]);
        ull ans((mul(A % mod, b % mod) % mod) + (mul(B % mod, b % mod) % mod));
        return ans % mod;
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
    {
        cin >> a >> b >> mod >> k;
        if (k == 1)
        {
            cout << b % mod << " \n"[t != 0];
            continue;
        }
        cout << matrixMul().solve() << " \n"[t != 0];
    }
    return 0;
}