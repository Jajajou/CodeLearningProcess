/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "nb" //pls dont forget your task's name
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
int n(0);

class matrix
{
public:
    int res[2][2];

    matrix()
    {
        res[0][0] = 6, res[0][1] = -3;
        res[1][0] = 1, res[1][1] = 0;
    }

    matrix(int tmp[][2]) { forup(int, i, 0, 1) forup(int, j, 0, 1) res[i][j] = tmp[i][j]; }

    matrix operator%(const ll &k)
    {
        int tmp[2][2];
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                tmp[i][j] = res[i][j] % k;
        return matrix(tmp);
    }

    matrix operator*(const matrix &m)
    {
        int tmp[2][2];
        forup(int, i, 0, 1) forup(int, j, 0, 1)
        {
            tmp[i][j] = [&]()
            {
                int cp(0);
                forup(int, k, 0, 1) cp = (cp % 1000 + (((res[i][k] % 1000) * (m.res[k][j] % 1000)) % 1000) + 1000 * 1000) % 1000;
                return cp;
            }();
        }
        return matrix(tmp) % 1000;
    }

    matrix operator^=(const int &n)
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
    cin >> n;
    matrix tmp = matrix() ^= (--n);
    int tmpRes(((tmp.res[0][0] % 1000 * 6) % 1000) + ((tmp.res[0][1] % 1000 * 2) % 1000) % 1000);
    tmpRes = (tmpRes - 1) % 1000;
    string res(to_string((tmpRes - 1) % 1000));
    while (res.length() < 3)
        res = "0" + res;
    cout << res;
    return 0;
}