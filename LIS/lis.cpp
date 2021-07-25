/* 
#include <bits/stdc++.h>
#define name "lis" //pls dont forget your task's name
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

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;

    int res(0), x(0), dp[n + 1];
    forup(int, i, 1, n)
    {
        cin >> x;
        int p = lower_bound(dp, dp + res, x) - dp;
        if (p == res)
        {
            ++res;
            dp[p] = x;
        }
        else
            dp[p] = min(dp[p], x);
    }
    cout << res;
    return 0;
} */
/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "lis" //pls dont forget your task's name
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

const void IO()
{
    Fin(name);
    Fout(name);
}
struct RMQ
{
    int n;
    vector<int> seg;
    const int ID = 0;

    void init(int n0)
    {
        n = n0;
        seg.assign(2 * n, ID);
    }

    void upd(int p, int v)
    {
        seg[p += n] = v;
        for (p /= 2; p; p /= 2)
            seg[p] = max(seg[2 * p], seg[2 * p + 1]);
    }

    int qry(int l, int r)
    {
        int ql = ID, qr = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                ql = max(ql, seg[l++]);
            if (r & 1)
                qr = max(seg[--r], qr);
        }
        return max(ql, qr);
    }
} dp;
int n;
vector<int> v, cmp;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    auto cid = [&](int x)
    { return lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin(); };

    dp.init(cmp.size());
    dp.upd(cid(v[0]), 1);
    for (int i = 1; i < n; ++i)
        dp.upd(cid(v[i]), dp.qry(0, cid(v[i]) - 1) + 1);
    cout << dp.qry(0, cmp.size() - 1) << "\n";
    return 0;
}