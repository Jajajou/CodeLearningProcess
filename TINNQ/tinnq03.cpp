/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "tinnq03" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
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
// #define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
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
typedef pair<float, float> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
struct Sqr
{
    ii a, b, c, d;
};
vector<Sqr> sqr;

void createSqr(int r)
{
    forup(int, x, 0, r - 1) forup(int, y, 0, r - 1) sqr.pb({
        {1.0 * x, 1.0 * y},
        {1.0 * (x + 1), 1.0 * y},
        {1.0 * x, 1.0 * (y + 1)},
        {1.0 * (x + 1), 1.0 * (y + 1)},
    });
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    while (cin >> n)
    {
        int d(2 * n - 1);
        float r(d / 2.0);
        int sqrIn(0), sqrOn(0);
        sqr.clear();
        createSqr(n);
        for (Sqr v : sqr)
        {
            int cp(0);
            cp += (v.a.fi * v.a.fi + v.a.se * v.a.se <= r * r);
            cp += (v.b.fi * v.b.fi + v.b.se * v.b.se <= r * r);
            cp += (v.c.fi * v.c.fi + v.c.se * v.c.se <= r * r);
            cp += (v.d.fi * v.d.fi + v.d.se * v.d.se <= r * r);
            if (cp == 4)
                ++sqrIn;
            elif (cp)++ sqrOn;
        }
        cout << 4 * sqrOn << ' ' << 4 * sqrIn << '\n';
    }
    return 0;
}