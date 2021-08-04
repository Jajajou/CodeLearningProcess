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

const void IO()
{
   Fin(name);
   Fout(name);
}
const int BASE = 1e9;
typedef vector<int> big;
void fix(big &a)
{
   while (a.size() >= 2 && a.back() == 0)
      a.pop_back();
}
big operator*(const big &a, const big &b)
{
   big res(a.size() + b.size() + 1, 0);
   for (int i = 0; i < a.size(); ++i)
   {
      int tmp(0);
      for (int j = 0; j < b.size(); ++j)
      {
         ll s = (ll)res[i + j] + tmp + (ll)a[i] * b[j];
         res[i + j] = s % BASE;
         tmp = s / BASE;
      }
      if (tmp)
         res[i + b.size()] = tmp;
   }
   return fix(res), res;
}
big to_big(int x)
{
   assert(x < BASE);
   return big(1, x);
}
big operator+(big a, big b)
{
   big res;
   int tmp(0);
   fix(a), fix(b);
   for (int i = 0; i < max(a.size(), b.size()); ++i)
   {
      if (i < a.size())
         tmp += a[i];
      if (i < b.size())
         tmp += b[i];
      res.pb(tmp % BASE);
      tmp /= BASE;
   }
   if (tmp)
      res.pb(tmp % BASE);
   return fix(res), res;
}
big operator-(big a, big b)
{
   big res;
   int tmp(0);
   fix(a), fix(b);
   for (int i = 0; i < a.size(); ++i)
   {
      tmp += a[i];
      if (i < b.size())
         tmp -= b[i];
      if (tmp < 0)
         res.pb(tmp + BASE), tmp = -1;
      else
         res.pb(tmp), tmp = 0;
   }
   return fix(res), res;
}
bool operator<(const big &a, const big &b)
{
   if (a.size() != b.size())
      return a.size() < b.size();
   for (int i = a.size() - 1; i >= 0; i--)
      if (a[i] != b[i])
         return a[i] < b[i];
   return false;
}
big operator/(big a, int x)
{
   assert(x < BASE);
   for (int i = (int)a.size() - 1, r = 0; i >= 0; --i, r %= x)
   {
      r = r * BASE + a[i];
      a[i] = r / x;
   }
   return fix(a), a;
}
int operator%(const big &a, int x)
{
   int r = 0;
   for (int i = (int)a.size() - 1; i >= 0; --i)
      r = (r * BASE + a[i]) % x;
   return r;
}
istream &operator>>(istream &cin, big &a)
{
   string s;
   cin >> s;
   while (s.size() % 9)
      s = '0' + s;
   for (int i = 0; i < s.size(); i += 9)
   {
      ll b = 0;
      forup(int, j, i, i + 9 - 1) b = b * 10 + (s[j] - '0');
      a.insert(a.begin(), b);
   }
   return fix(a), cin;
}
ostream &operator<<(ostream &cout, const big &a)
{
   printf("%d", a.back());
   for (int i = (int)a.size() - 2; i >= 0; i--)
      printf("%09d", a[i]);
   return cout;
}
big a, b;

void read()
{
   cin >> a >> b;
}

void solve()
{
   cout << a;
}

int main()
{
   boost();
#ifndef ONLINE_JUDGE
   IO();
#endif
   read();
   solve();
   return 0;
}