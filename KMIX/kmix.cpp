/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "kmix" //pls dont forget your task's name
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
    long long x, y;
    Point() {}
    Point(ll a, ll b) : x(a), y(b) {}
    bool operator<(const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    long long cross(const Point &p, const Point &q) const { return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); }
} p[maxn], poly[maxn];
istream &operator>>(istream &cin, Point &x)
{
    ll a, b;
    cin >> a >> b;
    return x = Point(a, b), cin;
}
ostream &operator<<(ostream &cout, Point p) { return cout << p.x << ' ' << p.y, cout; }
int n(0), q(0), k(0);

void convexHull()
{
    sort(p, p + n);
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && poly[k - 2].cross(poly[k - 1], p[i]) <= 0)
            --k;
        poly[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && poly[k - 2].cross(poly[k - 1], p[i]) <= 0)
            --k;
        poly[k++] = p[i];
    }
    --k;
}

bool inRectangle(Point a, Point b, Point c, Point cp)
{
    ll s(abs(a.cross(b, c))), z(abs(cp.cross(a, b)) + abs(cp.cross(a, c)) + abs(cp.cross(b, c)));
    return s == z;
}
bool check(Point cp)
{
    int l(0), r(k - 1);
    while (l <= r)
    {
        int mid((l + r) / 2);
        if (poly[0].cross(poly[mid], cp) >= 0)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return inRectangle(poly[0], poly[l - 1], poly[l], cp);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 0, n - 1) cin >> p[i];
    convexHull();
    Point cp;
    cin >> q;
    for (int i(0); i < q && cin >> cp; ++i)
        cout << (check(cp) ? "YES\n" : "NO\n");
    return 0;
}