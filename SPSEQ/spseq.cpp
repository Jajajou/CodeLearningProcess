/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "spseq" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
#define maxn 101001
#define elif else if
#define pri_q priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define Fin(name) freopen(name ".inp", "r", stdin)
#define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
#define Fout(name) freopen("D:\\C++\\SPSEQ\\" name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin

template <class val>
val getBit(val x, val pos)
{
    return x >> pos & 1;
}
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }
template <class val>
const void maximize(val &a, val b)
{
    a = max(a, b);
}
template <class val>
const void minimize(val &a, val b)
{
    a = min(a, b);
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), ar[int(1e5) + 51], lis[int(1e5) + 51], lds[int(1e5) + 51];

namespace DP
{
    int val[int(1e5)], len;
    void LIS()
    {
        len = 0;
        forup(int, i, 1, n + 1) val[i] = int(1e6);
        val[0] = -1;
        forup(int, i, 0, n - 1)
        {
            int p = lower_bound(val, val + len, ar[i]) - val;
            if (p == len)
            {
                ++len;
                val[p] = ar[i];
            }
            else
                minimize(val[p], ar[i]);
            lis[i] = len;
        }
    }
    void LDS()
    {
        len = 0;
        forup(int, i, 1, n + 1) val[i] = int(1e6);
        val[0] = -1;
        fordown(int, i, n - 1, 0)
        {
            int p = lower_bound(val, val + len, ar[i]) - val;
            if (p == len)
            {
                ++len;
                val[p] = ar[i];
            }
            else
                minimize(val[p], ar[i]);
            lds[i] = len;
        }
    }
    void show()
    {
        int res(0);
        forup(int, i, 0, n - 1) maximize(res, 2 * min(lis[i], lds[i]) - 1);
        cout << res;
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 0, n - 1) cin >> ar[i];
    DP::LIS();
    DP::LDS();
    DP::show();
    return 0;
}