/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "" // pls dont forget your task's name
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
#define Fin(name) freopen(name ".inp", "r", stdin)
// #define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
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
const val maximize(val &a, val b) { return a <= b ? a = b : 0; }
template <class val>
const val minimize(val &a, val b) { return a >= b ? a = b : 0; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}

int main()
{
    boost();
    int min1, min2_10, min11, s, res(0), cp(0);
    cin >> min1 >> min2_10 >> min11 >> s;
    if (s >= min1)
        ++res, s -= min1;
    else
        return cout << res, 0;
    fordown(int, i, 9, 1) if (i * min2_10 <= s)
    {
        cp = 1, res += i, s -= (i * min2_10);
        break;
    }
    if (cp)
    {
        while (s >= min11)
            ++res, s -= min11;
    }
    return cout << res, 0;
}