/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "watermove" //pls dont forget your task's name
#define maxn int(1e6) + 16
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

struct pt
{
    double x, y;
    pt(double a = 0.0, double b = 0.0)
    {
        x = a;
        y = b;
    }
} p[maxn];
int n(0), arr[maxn], s[maxn];
vector<pt> up, down;

bool cmp(pt a, pt b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

double size(vector<pt> poly, int k)
{
    double S = (poly[k - 1].x - poly[0].x) * (poly[k - 1].y + poly[0].y) / 2;
    for (int i = 1; i < k; ++i)
        S += (poly[i - 1].x - poly[i].x) * (poly[i - 1].y + poly[i].y) / 2;
    return S;
}

void convex_hull(pt a[])
{
    if (n == 1)
    {
        return;
    }
    sort(a, a + n + 1, &cmp);
    pt p1 = a[0], p2 = a[n];
    up.push_back(p1);
    down.push_back(p1);

    for (size_t i = 1; i <= n; ++i)
    {
        if (i == n || cw(p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == n || ccw(p1, a[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    printf("%0.1f\n", abs(size(up, up.size())) - abs(size(down, down.size())));
}

void read()
{
    cin >> n;
    forup(int, i, 1, n) cin >> arr[i], s[i] = s[i - 1] + arr[i];
    forup(int, i, 0, n) p[i] = {(double)(i), (double)(s[i])};
    convex_hull(p);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    return 0;
}