/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "matrix" //pls dont forget your task's name
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
    int n, m, p;
    ll a[200][200], b[200][200];

    ll **mul(ll matrixA[][200], ll matrixB[][200])
    {
        ll **res;
        res = new ll *[n];
        for (int i = 0; i < n; ++i)
        {
            res[i] = new ll[p];
            for (int j = 0; j < p; ++j)
                res[i][j] = [&]()
                {
                    ll cp(0);
                    for (int k = 0; k < m; ++k)
                        cp += a[i][k] * b[k][j];
                    return cp;
                }();
        }
        return res;
    }

public:
    void solve(int N, int M, int P)
    {
        n = N, m = M, p = P;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < p; ++j)
                cin >> b[i][j];

        ll **res = mul(a, b);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < p; ++j)
                cout << res[i][j] << " \n"[j == p - 1 && i != n - 1];
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0), p(0);
    cin >> n >> m >> p;
    matrixMul().solve(n, m, p);
    return 0;
}