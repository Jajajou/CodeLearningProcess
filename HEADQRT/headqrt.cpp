/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "headqrt" //pls dont forget your task's name
#define maxn int(3e4) + 34
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
ll sqr(int x) { return 1LL * x * x; }
struct Point
{
    int x, y;
    bool operator<(const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    Point operator+(const Point &b) const { return Point{x + b.x, y + b.y}; }
    Point operator-(const Point &b) const { return Point{x - b.x, y - b.y}; }
    ll operator*(const Point &b) const { return (ll)(x * b.y) - (ll)(y * b.x); }
    void operator+=(const Point &b) { x += b.x, y += b.y; }
    void operator-=(const Point &b) { x -= b.x, y -= b.y; }
    void operator*=(const int k) { x *= k, y *= k; }
    ll cross(const Point &b, const Point &c) const
    {
        return (b - *this) * (c - *this);
    }
    ll dist(const Point &m) const
    {
        return sqr(m.x - x) + sqr(m.y - y);
    }
} p1[maxn], p2[maxn], poly1[maxn], poly2[maxn];
istream &operator>>(istream &cin, Point &p)
{
    int a, b;
    cin >> a >> b;
    return p = {a, b}, cin;
}
ostream &operator<<(ostream &cout, Point p) { return cout << p.x << ' ' << p.y << ' ', cout; }
int fix(ll x) { return (x > 0) ? 1 : (x == 0 ? 0 : -1); }
int n(0), n1(0), n2(0);

void convexHull(Point p[], Point &poly[], int &n)
{
    sort(p, p + n);
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && poly[k - 1].cross(poly[k - 2], p[i]) <= 0)
            --k;
        poly[k++] = p[i];
    }
    for (int i = n - 1, t = k + 1; i >= 0; --i)
    {
        while (k >= t && poly[k - 1].cross(poly[k - 2], p[i]) <= 0)
            --k;
        poly[k++] = p[i];
    }
    n = k;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a, b, c;
        forup(int, i, 0, n - 1)
        {
            cin >> a >> b >> c;
            if (c)
                p1[n1++] = {a, b};
            else
                p2[n2++] = {a, b};
        }
        if (n == 2 && n1 > 0 && n2 > 0)
        {
            cout << int(sqrt(p1[n1 - 1].dist(p2[n2 - 1]))) << endl;
            continue;
        }
        convexHull(p1, poly1, n1);
        convexHull(p2, poly1, n2);
        cout << max(ll(sqrt(p1Max.dist(p2Min))), ll(sqrt(p2Max.dist(p1Min)))) << endl;
    }
    return 0;
}