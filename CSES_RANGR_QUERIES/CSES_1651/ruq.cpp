/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "ruq" //pls dont forget your task's name
#define maxn int(1e5) + 25
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
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
template <class val>
class BIT
{
private:
    vector<val> tree;
    int n;

public:
    void init(int _n) { n = _n, tree.assign(n + 1, 0); }
    void update(int pos, val value)
    {
        for (; pos <= n; pos += pos & (-pos))
            tree[pos] += value;
    }
    val get(int pos)
    {
        val res((val)0);
        for (; pos; pos -= pos & (-pos))
            res += tree[pos];
        return res;
    }
};
BIT<ll> bit;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), q(0);
    cin >> n >> q;
    vector<ll> a(n + 1, 0), diff(n + 1, 0);
    bit.init(n);
    for (int i(1); i <= n && cin >> a[i]; ++i)
        diff[i] = a[i] - a[i - 1], bit.update(i, diff[i]);
    while (q--)
    {
        int id(0);
        cin >> id;
        if (2 - id)
        {
            int l, r;
            ll val;
            cin >> l >> r >> val;
            bit.update(l, val);
            bit.update(r + 1, -val);
        }
        else
        {
            int pos;
            cin >> pos;
            cout << bit.get(pos) << endl;
        }
    }
    return 0;
}