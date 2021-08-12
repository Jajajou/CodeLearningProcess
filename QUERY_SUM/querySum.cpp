/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "querySum" //pls dont forget your task's name
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

const void IO()
{
    Fin(name);
    Fout(name);
}
struct BIT
{
    int n;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n + 1, 0) {}
    void update(int pos, ll val)
    {
        for (; pos <= n; pos += pos & (-pos))
            bit[pos] += val;
    }
    ll get(int pos)
    {
        ll res(0);
        for (; pos; pos -= pos & (-pos))
            res += bit[pos];
        return res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), q(0);
    cin >> n >> q;
    vector<ll> c(n);
    for (ll &v : c)
        cin >> v;
    int i(0);
    BIT tree(n);
    for (ll &v : c)
        tree.update(++i, v);
    while (q--)
    {
        int cp(0), a(0);
        ll b(0);
        cin >> cp >> a >> b;
        if (2 - cp)
        {
            tree.update(a, b);
        }
        else
        {
            cout << tree.get(b) - tree.get(a - 1) << endl;
        }
    }
    return 0;
}