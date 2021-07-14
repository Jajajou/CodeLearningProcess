/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "loco" //pls dont forget your task's name
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
template <class val>
val mul(val a, val b, val m)
{
    if (!b)
        return 0;
    if (!(b - 1))
        return a;
    return b & 1 ? (mul(a, b >> 1, m) * 2 + a) % m : (mul(a, b >> 1, m) * 2) % m;
}

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
ll n(0), maxn(0);

class matrix
{
public:
    ll res[3][3];

    matrix()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                res[i][j] = 0LL;
        for (int i = 0; i < 3; ++i)
            res[0][i] = 1LL;
        res[1][0] = res[2][1] = 1LL;
    }

    matrix(ll tmp[][3]) { forup(int, i, 0, 2) forup(int, j, 0, 2) res[i][j] = tmp[i][j]; }

    matrix operator%(const ll &k)
    {
        ll tmp[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                tmp[i][j] = res[i][j] % k;
        return matrix(tmp);
    }

    matrix operator*(const matrix &m)
    {
        ll tmp[3][3];
        forup(int, i, 0, 2) forup(int, j, 0, 2)
        {
            tmp[i][j] = [&]()
            {
                ll cp(0);
                forup(int, k, 0, 2) cp = ((cp % maxn) + (mul(res[i][k] % maxn, m.res[k][j] % maxn, maxn) % maxn)) % maxn;
                return cp;
            }();
        }
        return matrix(tmp) % maxn;
    }

    matrix operator^=(const ll &n)
    {
        if (n <= 1)
            return matrix();
        matrix res = *this ^= (n >> 1);
        return n & 1 ? res * res * matrix() : res * res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> maxn;
    matrix ans = matrix() ^= n;
    cout << ans.res[0][0];
    return 0;
}