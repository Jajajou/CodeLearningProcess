/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "plp" //pls dont forget your task's name
#define maxn int(1e6)
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
    Point(){};
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    bool operator<(const Point &v) { return make_pair(x, y) < make_pair(v.x, v.y); }
    Point operator-(const Point &v) { return Point(x - v.x, y - v.y); }
} poly[maxn];
istream &operator>>(istream &cin, Point &x)
{
    ll a, b;
    cin >> a >> b;
    return x = {a, b}, cin;
}
int n(0);

ll size(Point p[], int k = n)
{
    long long S = (poly[k].x - poly[0].x) * (poly[k].y + poly[0].y);
    for (int i = 1; i <= k; ++i)
        S += (poly[i - 1].x - poly[i].x) * (poly[i - 1].y + poly[i].y);
    return S;
    printf("%lld\n", S);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 0, n - 1) cin >> poly[i];
    poly[n] = poly[0];
    ll area(abs(size(poly)) / 2), onPoly(0);
    forup(int, i, 0, n - 1)
    {
        if (poly[i].x == poly[i + 1].x)
            onPoly += abs(poly[i].y - poly[i + 1].y);
        elif (poly[i].y == poly[i + 1].y)
            onPoly += abs(poly[i].x - poly[i + 1].x);
        else onPoly += __gcd(abs(poly[i].y - poly[i + 1].y), abs(poly[i].x - poly[i + 1].x));
    }
    cout << area + 1 - onPoly / 2 << ' ' << onPoly;
    return 0;
}