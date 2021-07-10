/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "bones" //pls dont forget your task's name
#define maxn 100
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

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int x(0), y(0), z(0);
    cin >> x >> y >> z;
    int sum[x + y + z], res(0), cpSum(0);
    forup(int, i, 3, x + y + z) sum[i] = 0;

    forup(int, xx, 1, x) forup(int, yy, 1, y) forup(int, zz, 1, z)
    {
        ++sum[xx + yy + zz];
        res = (sum[xx + yy + zz] > cpSum) ? cpSum = sum[xx + yy + zz], xx + yy + zz : res;
    }
    cout << res;
    return 0;
}