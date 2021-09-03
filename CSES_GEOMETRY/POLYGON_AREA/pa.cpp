/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "pa" //pls dont forget your task's name
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
struct Point
{
    ll x, y;
    bool operator<(const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
} p[1001];
istream &operator>>(istream &cin, Point &p)
{
    ll a, b;
    cin >> a >> b;
    return p = {a, b}, cin;
}
ostream &operator<<(ostream &cout, Point p) { return cout << p.x << ' ' << p.y, cout; }
int n(0);

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    ll res(0);
    cin >> n;
    forup(int, i, 0, n - 1) cin >> p[i];
    res = (p[n - 1].x - p[0].x) * (p[n - 1].y + p[0].y);
    forup(int, i, 1, n - 1) res += (p[i - 1].x - p[i].x) * (p[i].y + p[i - 1].y);
    cout << abs(res);
    return 0;
}