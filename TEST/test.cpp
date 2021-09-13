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
typedef tuple<int, int, int> iii;

const void IO()
{
   Fin(name);
   Fout(name);
}
constexpr int bits(int x)
{ // assert(x >= 0); // make C++11 compatible until USACO updates ...
   return x == 0 ? 0 : 31 - __builtin_clz(x);
}

void countingSort(vector<int> &arr)
{
   int max = *max_element(arr.begin(), arr.end()),
       min = *min_element(arr.begin(), arr.end()),
       rangeDiff = max - min + 1;
   vector<int> count(rangeDiff, 0);
   vector<int> res(arr.size());
   for (int v : arr)
      ++count[v - min];
   for (int i(1); i < count.size(); ++i)
      count[i] += count[i - 1];
   for (int i = arr.size() - 1; i >= 0; --i)
   {
      res[count[arr[i] - min] - 1] = arr[i];
      count[arr[i] - min]--;
   }
   return (void)(arr = res);
}

int main()
{
   boost();
#ifndef ONLINE_JUDGE
   IO();
#endif
   vector<int> arr(10);
   for (int &v : arr)
      v = -50 + rand() % (50 * 2 + 1);
   for (int v : arr)
      cout << v << ' ';
   cut;
   countingSort(arr);
   for (int v : arr)
      cout << v << ' ';
   return 0;
}