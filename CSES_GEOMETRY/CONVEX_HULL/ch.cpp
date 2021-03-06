/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "ch" //pls dont forget your task's name
#define maxn int(2e5) + 25
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
    long long x, y;
    bool operator<(const Point &v) const { return make_pair(x, y) < make_pair(v.x, v.y); }
    Point operator+(const Point &b) const { return Point{x + b.x, y + b.y}; }
    Point operator-(const Point &b) const { return Point{x - b.x, y - b.y}; }
    ll operator*(const Point &b) const { return (ll)x * b.y - (ll)y * b.x; }
    void operator+=(const Point &b) { x += b.x, y += b.y; }
    void operator-=(const Point &b) { x -= b.x, y -= b.y; }
    void operator*=(const int k) { x *= k, y *= k; }
    ll cross(const Point &b, const Point &c) const
    {
        return (b - *this) * (c - *this);
    }
} p[maxn], poly[maxn];
istream &operator>>(istream &cin, Point &p)
{
    ll a, b;
    cin >> a >> b;
    return p = {a, b}, cin;
}
ostream &operator<<(ostream &cout, Point p) { return cout << p.x << ' ' << p.y, cout; }
int fix(ll x) { return (x > 0) ? 1 : (x == 0 ? 0 : -1); }
int n(0), k(0);

void convexHull()
{
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && poly[k - 1].cross(poly[k - 2], p[i]) < 0)
            --k;
        poly[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && poly[k - 1].cross(poly[k - 2], p[i]) < 0)
            --k;
        poly[k++] = p[i];
    }
    cout << --k << endl;
    forup(int, i, 0, k - 1) cout << poly[i] << endl;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 0, n - 1) cin >> p[i];
    sort(p, p + n);
    convexHull();
    return 0;
}