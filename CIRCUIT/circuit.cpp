/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "circuit" //pls dont forget your task's name
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
struct P
{
    int x, y, d;
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
} p[1001];
istream &operator>>(istream &cin, P &x)
{
    int a, b, c;
    cin >> a >> b >> c;
    return x = {a, b, c}, cin;
}

bool lsi(P p1, P p2, P p3, P p4)
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
        return 1;
    return 0;
}
int n(0), state[1001][1001], pref[1001][1001];

void next(int &x)
{
    if (x == 1)
        x = 0;
    else
        x = 1;
}

void reset()
{
    forup(int, i, 1, n) forup(int, j, 1, n) pref[i][j] = 0;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 1, n) cin >> p[i];
    // forup(int, i, 1, n) state[i][i] = -1;
    take(1, 1);
    return 0;
}