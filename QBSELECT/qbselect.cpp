/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "qbselect" //pls dont forget your task's name
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
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
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
int n(0);
ll ar[4][int(1e4)], dp[int(1e4)][1 << 4];

ll sumState(int mask, int col)
{
    ll res(0);
    forup(int, i, 0, 3) if (getBit(mask, i)) res += ar[i][col];
    return res;
}

bool verticalCheck(int mask)
{
    forup(int, i, 1, 3) if (getBit(mask, i) && getBit(mask, i - 1)) return 0;
    return 1;
}

bool horizontalCheck(int mask1, int mask2)
{
    forup(int, i, 0, 3) if (getBit(mask1, i) && getBit(mask2, i)) return 0;
    return 1;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 0, 3) forup(int, j, 0, n - 1) cin >> ar[i][j];
    forup(int, i, 0, n - 1)
    {
        forup(int, mask1, 0, (1 << 4) - 1) if (verticalCheck(mask1))
        {
            ll k(-ll(1e16));
            forup(int, mask2, 0, (1 << 4) - 1) if (verticalCheck(mask2) && horizontalCheck(mask1, mask2))
                maximize(k, i > 0 ? dp[i - 1][mask2] : 0);
            dp[i][mask1] = k + sumState(mask1, i);
        }
    }
    ll res(-ll(1e16));
    forup(int, mask, 0, (1 << 4) - 1) maximize(res, dp[n - 1][mask]);
    cout << res;
    return 0;
}