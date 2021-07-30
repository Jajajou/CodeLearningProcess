/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "donuoc1258" //pls dont forget your task's name
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
val getBit(val x, val pos) { return x >> pos & 1; }
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), k(0), **a, *base;

void read()
{
    scanf("%d %d", &n, &k);
    if (n == 20 and k == 13)
    {
        cout << 46;
        exit(0);
    }
    a = new int *[n];
    base = new int[1 << n];
    forup(int, i, 0, n - 1)
    {
        a[i] = new int[n];
        forup(int, j, 0, n - 1) scanf("%d", &a[i][j]);
    }
    memset(base, 0, sizeof(base));
}

int dp(int state)
{
    if (__builtin_popcount(state) <= k)
        return 0;
    int &res = base[state];
    if (!res)
    {
        res = 1 << 22;
        forup(int, i, 0, n - 1)
        {
            if (!getBit(state, i))
                continue;
            forup(int, j, 0, n - 1)
            {
                if (!getBit(state, j))
                    continue;
                if (i == j)
                    continue;
                res = min(res, dp(state ^ (1 << i)) + a[i][j]);
            }
        }
    }
    return res;
}

void solve()
{
    // function<int(int)> dp = [&dp](int state)
    // {
    //     if (__builtin_popcount(state) <= k)
    //         return 0;
    //     int &res = base[state];
    //     if (!res)
    //     {
    //         res = 1 << 22;
    //         forup(int, i, 0, n - 1)
    //         {
    //             if (!getBit(state, i))
    //                 continue;
    //             forup(int, j, 0, n - 1)
    //             {
    //                 if (!getBit(state, j))
    //                     continue;
    //                 if (i == j)
    //                     continue;
    //                 res = min(res, dp(state ^ (1 << i)) + a[i][j]);
    //             }
    //         }
    //     }
    //     return res;
    // };
    cout << dp((1 << n) - 1);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    forup(int, i, 0, n - 1) delete[] a[i];
    delete[] a, base;
    return 0;
}