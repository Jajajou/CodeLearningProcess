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
struct Point
{
    ll x, y;
    Point(ll a = 0, ll b = 0) { x = a, y = b; }
} p[maxn];
bool cw(const Point &a, const Point &b, const Point &c)
{
    return (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y) > 0;
}
int n(0);
ll arr[maxn], s[maxn];

void read()
{
    cin >> n;
    forup(int, i, 1, n) cin >> arr[i], s[i] = s[i - 1] + arr[i];
    forup(int, i, 0, n) p[i] = {i, s[i]};
}

void solve()
{
    int hullSize(n);
    fordown(int, i, n - 1, 0)
    {
        while (hullSize != n and !cw(p[hullSize - 1], p[hullSize], p[i]))
            --hullSize;
        p[++hullSize] = p[i];
    }
    ll res(0);
    forup(int, i, 1, hullSize) res += (p[i - 1].x - p[i].x) * (p[i - 1].y + p[i].y);
    printf("%lld%s", abs(res / 2), res & 1 ? ".5" : ".0");
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