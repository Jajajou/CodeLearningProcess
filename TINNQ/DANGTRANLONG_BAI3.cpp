/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "ttnq3" // pls dont forget your task's name
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
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), a[maxn], k(0), res(-1);
vector<int> compress;
struct BIT
{
    int n, k;
    vector<int> tree;
    void init(int _n, int _k)
    {
        n = _n;
        k = _k;
        tree.assign(2 * n + 1, k + 1);
    }
    void update(int pos, int val)
    {
        for (pos; pos <= n; pos += pos & -pos)
            minimize(tree[pos], val);
    }

    int getMin(int pos)
    {
        int res(k + 1);
        for (pos; pos > 0; pos -= pos & -pos)
            minimize(res, tree[pos]);
        return res;
    }
} bit;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> k;
    forup(int, i, 1, n) cin >> a[i];
    forup(int, i, 1, n)
    {
        a[i] += a[i - 1];
        compress.pb(a[i]);
        compress.pb(a[i] - k);
    }
    compress.pb(0);
    compress.pb(0 - k);
    sort(allVi(compress));
    compress.erase(unique(allVi(compress)), compress.end());
    bit.init((int)compress.size(), n);
    forup(int, i, 1, n)
    {
        int x = lower_bound(allVi(compress), a[i - 1]) - compress.begin();
        bit.update(x, i);
        x = lower_bound(allVi(compress), a[i] - k) - compress.begin();
        int j = bit.getMin(x);
        if (j == n + 1)
            continue;
        maximize(res, i - j + 1);
    }
    cout << res;
    return 0;
}