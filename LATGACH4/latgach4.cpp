/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "latgach4" //pls dont forget your task's name
#define maxn 111539786
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

class matrix
{
public:
    ll res[2][2];
    matrix() { res[0][0] = res[1][0] = res[0][1] = 1, res[1][1] = 0; }
    matrix(ll a, ll b, ll c, ll d) { res[0][0] = a, res[0][1] = b, res[1][0] = c, res[1][1] = d; }
    matrix operator%(const ll &k) { return matrix(res[0][0] % k, res[0][1] % k, res[1][0] % k, res[1][1] % k); }
    matrix operator*(const matrix &m)
    {
        return matrix(res[0][0] * m.res[0][0] % maxn + res[0][1] * m.res[1][0] % maxn,
                      res[0][0] * m.res[0][1] % maxn + res[0][1] * m.res[1][1] % maxn,
                      res[1][0] * m.res[0][0] % maxn + res[1][1] * m.res[1][0] % maxn,
                      res[1][0] * m.res[0][1] % maxn + res[1][1] * m.res[1][1] % maxn) %
               maxn;
    }
    matrix operator^=(const int &n)
    {
        if (n == 1)
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
    int q(0);
    cin >> q;
    while (q--)
    {
        int n(0);
        cin >> n;
        cout << (matrix() ^= n).res[0][0] << "\n";
    }
    return 0;
}