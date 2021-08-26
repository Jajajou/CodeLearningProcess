/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "flower" //pls dont forget your task's name
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
struct BIT
{
    int n;
    vector<ll> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int pos, ll val)
    {
        for (; pos <= n; pos += pos & (-pos))
            maximize(tree[pos], val);
    }
    ll get(int pos)
    {
        ll res(0);
        for (; pos; pos -= pos & (-pos))
            maximize(res, tree[pos]);
        return res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;
    BIT bit(n);
    vector<int> h(n, 0), w(n, 0);
    vector<ll> dp(n + 1, 0);
    for (int &c : h)
        cin >> c;
    for (int &c : w)
        cin >> c;
    forup(int, i, 1, n)
    {
        dp[i] = bit.get(h[i - 1] - 1) + w[i - 1];
        bit.update(h[i - 1], dp[i]);
    }
    ll res(0);
    forup(int, i, 1, n) maximize(res, dp[i]);
    cout << res;
    return 0;
}