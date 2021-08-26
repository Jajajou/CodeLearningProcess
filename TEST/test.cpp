/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "test" //pls dont forget your task's name
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
val getBit(val x, val pos)
{
   return x >> pos & 1;
}
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
   Fin(name);
   Fout(name);
}
constexpr int bits(int x)
{ // assert(x >= 0); // make C++11 compatible until USACO updates ...
   return x == 0 ? 0 : 31 - __builtin_clz(x);
}

int main()
{
   boost();
#ifndef ONLINE_JUDGE
   IO();
#endif
   int mask(0), i(0);
   forup(int, j, 0, 2) if ((mask & (1 << ((i + j) % 7))) == 0) cout << (1 << ((i + j) % 7)) << endl;
   forup(int, j, 0, 2) mask |= (1 << ((i + j) % 7));
   cout << "mask2: " << mask;
   return 0;
}