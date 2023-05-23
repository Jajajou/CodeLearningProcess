/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "219_xepthap" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
#define maxn int(1e6) + 16
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
const val maximize(val &a, val b) { return a <= b ? a = b : 0; }
template <class val>
const val minimize(val &a, val b) { return a >= b ? a = b : 0; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0);
struct ringStats
{
    int a, b, c;
    bool taken;
} ring[maxn];

bool cmp(ringStats &a, ringStats &b)
{
    return a.b > b.b;
}

int bs(int l, int r, int checkPoint)
{
    return 0;
}

void read()
{
    cin >> n;
    forup(int, i, 1, n) cin >> ring[i].a >> ring[i].b >> ring[i].c, ring[i].taken = 0;
}

void solve()
{
    sort(ring + 1, ring + n + 1, cmp);
    forup(int, i, 1, n) cout << ring[i].a << ring[i].b << ring[i].c << endl;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int x(1);
    cout << ::x;
    read();
    solve();
    return 0;
}