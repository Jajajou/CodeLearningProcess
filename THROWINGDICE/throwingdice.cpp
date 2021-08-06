/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "throwingdice" //pls dont forget your task's name
#define maxn 1000000007ll
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

class diceMatrix
{
public:
    ll dice[6][6] = {{0}};
    diceMatrix()
    {
        for (int i(0); i < 6; ++i)
            dice[0][i] = 1;
        for (int i(1); i < 6; ++i)
            dice[i][i - 1] = 1;
    }

    diceMatrix(ll x[][6])
    {
        for (int i(0); i < 6; ++i)
            for (int j(0); j < 6; ++j)
                dice[i][j] = x[i][j];
    }

    diceMatrix operator%(const ll &k)
    {
        for (int i(0); i < 6; ++i)
            for (int j(0); j < 6; ++j)
                dice[i][j] %= k;
        return *this;
    }

    diceMatrix operator*(const diceMatrix &m)
    {
        ll x[6][6] = {{0}};
        for (int i(0); i < 6; ++i)
        {
            for (int j(0); j < 6; ++j)
                x[i][j] = [&](int i, int j)
                {
                    ll res(0);
                    forup(int, k, 0, 5) res = (res % maxn + (dice[i][k] * m.dice[k][j] % maxn)) % maxn;
                    return res;
                }(i, j);
        }
        return diceMatrix(x);
    }

    diceMatrix operator^=(const ll &n)
    {
        if (n == 1)
            return diceMatrix();
        diceMatrix res = *this ^= (n >> 1);
        return n & 1 ? res * res * diceMatrix() : res * res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    // int preAns[6] = {1, 2, 4, 8, 16, 32};
    ll n(0);
    cin >> n;
    // if (n <= 6)
    //     return cout << preAns[n - 1], 0;
    cout << (diceMatrix() ^= n).dice[0][0];
}