/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "flowerChoose" //pls dont forget your task's name
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
vector<ll> st, dp;

void update(int pos, ll val, int l = 0, int r = dp.size() - 1, int id = 1)
{
    if (l == r)
    {
        dp[pos] = val;
        st[id] = val;
        return;
    }
    int mid((r + l) >> 1);
    if (pos > mid)
        update(pos, val, mid + 1, r, 2 * id + 1);
    else
        update(pos, val, l, mid, 2 * id);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

ll getMaxSum(int qL, int qR, int l = 0, int r = dp.size() - 1, int id = 1)
{
    if (qR < l || r < qL)
        return 0;
    if (l >= qL && r <= qR)
        return st[id];
    int mid((r + l) >> 1);
    ll leftChild(getMaxSum(qL, qR, l, mid, 2 * id)),
        rightChild(+getMaxSum(qL, qR, mid + 1, r, 2 * id + 1));
    return max(leftChild, rightChild);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;
    st.resize(4 * n + 10);
    dp.resize(n);
    fill(dp.begin(), dp.end(), 0);
    fill(st.begin(), st.end(), 0);
    vector<ll> a(n), h(n);
    for (ll &c : h)
        cin >> c;
    for (ll &c : a)
        cin >> c;
    forup(int, i, 0, n - 1)
    {
        if (h[i] == 1)
        {
            update(h[i] - 1, a[i]);
            continue;
        }
        update(h[i] - 1, getMaxSum(0, h[i] - 2) + a[i]);
    }
    ll res(LONG_MIN);
    for (ll cp : dp)
        res = max(res, cp);
    cout << res;
    return 0;
}