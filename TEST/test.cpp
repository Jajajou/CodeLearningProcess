/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "test" //pls dont forget your task's name
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
vector<int> ar, dp;

int DP(int k)
{
   if (k == 0)
      return 0;
   int &res = dp[k];
   if (res != -1)
      return res;
   res = 0;
   for (int v : ar)
      if (v <= k && DP(k - v) == 0)
      {
         res = 1;
         break;
      }
   return res;
}

int main()
{
   boost();
#ifndef ONLINE_JUDGE
   IO();
#endif
   int n(0), k(0);
   cin >> n >> k;
   ar.resize(n);
   dp.resize(k + 1, -1);
   for (int &v : ar)
      cin >> v;
   cout << (DP(k) ? "FIRST" : "SECOND");
   return 0;
}