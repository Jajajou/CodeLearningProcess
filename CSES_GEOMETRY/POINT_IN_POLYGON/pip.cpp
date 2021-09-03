/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "pip" //pls dont forget your task's name
#define maxn 1234
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
#define allVi(x) poly[0].begin(), poly[0].end()
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
    bool operator<(const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
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
} poly[maxn];
istream &operator>>(istream &cin, Point &p)
{
    ll a, b;
    cin >> a >> b;
    return p = {a, b}, cin;
}
ostream &operator<<(ostream &cout, Point p) { return cout << p.x << ' ' << p.y, cout; }
int n(0), q(0);

void check()
{
    function<bool(Point, Point, Point)> inLineAB = [&](Point a, Point b, Point cp)
    {
        if (cp.cross(a, b) != 0)
            return false;
        return (cp.x <= max(a.x, b.x) && cp.y <= max(a.y, b.y) && cp.x >= min(a.x, b.x) && cp.y >= min(a.y, b.y));
    };
    int cnt(0);
    forup(int, i, 1, n)
    {
        int j(i == n ? 1 : i + 1);
        if (inLineAB(poly[i], poly[j], poly[0]))
            return (void)(cout << "BOUNDARY\n");
        cnt += ((poly[i].x <= poly[0].x && poly[0].x < poly[j].x && poly[0].cross(poly[i], poly[j]) < 0) || (poly[j].x <= poly[0].x && poly[0].x < poly[i].x && poly[0].cross(poly[j], poly[i]) < 0)) ? 1 : 0;
    }
    if (cnt & 1)
        return (void)(cout << "INSIDE\n");
    else
        return (void)(cout << "OUTSIDE\n");
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> q;
    forup(int, i, 1, n) cin >> poly[i];
    forup(int, i, 0, q - 1)
    {
        cin >> poly[0];
        check();
    }
    return 0;
}