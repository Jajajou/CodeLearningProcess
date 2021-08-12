/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "querySumII" //pls dont forget your task's name
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
    vector<ll> diff2, diff1;
    BIT(int n) : n(n), diff1(n + 1, 0), diff2(n + 1, 0) {}
    void updateOnPoint(vector<ll> &tree, int pos, ll val)
    {
        for (; pos <= n; pos += pos & (-pos))
            tree[pos] += val;
    }
    void update1(int pos, ll val)
    {
        updateOnPoint(diff1, pos, val);
        // updateOnPoint(diff2, pos, val);
    }
    void update(int qL, int qR, ll val)
    {
        updateOnPoint(diff1, qL, (n - qL + 1) * val);
        updateOnPoint(diff1, qR + 1, (n - qR) * -val);
        updateOnPoint(diff2, qL, val);
        updateOnPoint(diff2, qR + 1, -val);
    }
    ll gett(int pos)
    {
        ll res(0);
        for (; pos > 0; pos -= pos & (-pos))
            res += diff2[pos];
        return res;
    }
    ll get(vector<ll> tree, int pos)
    {
        ll res(0);
        for (; pos; pos -= pos & (-pos))
            res += tree[pos];
        return res;
    }
    ll QSR(int qL, int qR)
    {
        if (!qL)
            return get(diff1, qR) - (n - qR) * get(diff2, qR);
        return get(diff1, qR) - (n - qR) * get(diff2, qR) - get(diff1, qL) + (n - qL) * get(diff2, qL);
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
    vector<ll> v(n);
    for (ll &a : v)
        cin >> a;
    int i(0);
    BIT tree(n);
    for (ll &a : v)
        tree.update1(++i, a);
    while (q--)
    {
        int cp(0), a(0), b(0);
        cin >> cp >> a >> b;
        if (2 - cp)
        {
            ll val(0);
            cin >> val;
            tree.update(a, b, val);
        }
        else
        {
            cout << tree.QSR(a - 1, b) << endl;
        }
    }
    return 0;
}