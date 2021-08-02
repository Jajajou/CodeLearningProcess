/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "lsi" //pls dont forget your task's name
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
};
const void IO()
{
    Fin(name);
    Fout(name);
}

void solve(P p1, P p2, P p3, P p4)
{
    function<bool(P, P, P)> inLineAB = [&](P a, P b, P cp)
    {
        return (cp.x <= max(a.x, b.x) && cp.y <= max(a.y, b.y) && cp.x >= min(a.x, b.x) && cp.y >= min(a.y, b.y));
    };
    function<short(P, P, P)> checkDirection = [&](P a, P b, P c)
    {
        ll cp(a.triangle(b, c));
        if (!cp)
            return 0;
        else
            return (cp > 0) ? 1 : 2;
    };
    int cp1(checkDirection(p3, p1, p2)), cp2(checkDirection(p4, p1, p2)), cp3(checkDirection(p1, p3, p4)), cp4(checkDirection(p2, p3, p4));
    if ((cp1 - cp2 and cp3 - cp4) || (!cp1 && inLineAB(p1, p2, p3)) || (!cp2 && inLineAB(p1, p2, p4)) || (!cp3 && inLineAB(p3, p4, p1)) || (!cp4 && inLineAB(p3, p4, p2)))
        return (void)(cout << "YES" << endl);
    return (void)(cout << "NO" << endl);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int x1, x2, x3, x4, y1, y2, y3, y4;
    P point1, point2, point3, point4;
    cin >> x1;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        point1 = {x1, y1}, point2 = {x2, y2}, point3 = {x3, y3}, point4 = {x4, y4};
        solve(point1, point2, point3, point4);
    }
    return 0;
}