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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
struct P
{
   int x, y;
   void read()
   {
      cin >> x >> y;
   }
   P operator-(const P &b) const
   {
      return {x - b.x, y - b.y};
   }
   void operator-=(const P &b)
   {
      x -= b.x;
      y -= b.y;
   }
   ll operator*(const P &b) const
   {
      return (ll)x * b.y - (ll)y * b.x;
   }
   ll triangle(const P &b, const P &c) const
   {
      return (b - *this) * (c - *this);
   }
   bool operator<(const P &b) const
   {
      return make_pair(x, y) < make_pair(b.x, b.y);
   }
   ll Dist(const P &b) const
   {
      return (ll)(x - b.x) * (x - b.x) + (ll)(y - b.y) * (y - b.y);
   }
};
const void IO()
{
   Fin(name);
   Fout(name);
}

void read()
{
}

void solve()
{
}

int Maxlen(int arr[], int n)
{
   int ans = 0;
   int count = 0;
   for (int i = 0; i < n; i++)
   {

      // If even element
      // is encountered
      if (arr[i] % 2 == 0)
         count = 0;
      else
         count++;

      // Update maximum
      ans = max(ans, count);
   }
   return ans;
}

int main()
{
   boost();
#ifndef ONLINE_JUDGE
   IO();
#endif
   int arr[] = {1, -2, -3, -4, 5};
   int n = sizeof(arr) / sizeof(int);

   cout << Maxlen(arr, n) << endl;
   return 0;
}