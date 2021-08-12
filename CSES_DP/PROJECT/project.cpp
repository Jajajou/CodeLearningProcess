/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "project" //pls dont forget your task's name
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
map<ll, ll> cnt;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;
    vector<ll> a(n), b(n), p(n);
    forup(int, i, 0, n - 1)
    {
        cin >> a[i] >> b[i] >> p[i];
        cnt[a[i]];
        cnt[++b[i]];
    }
    int m(0);
    for (auto &k : cnt)
        k.se = m++;
    vector<vector<ii>> qp(m);
    forup(int, i, 0, n - 1)
    {
        qp[cnt[b[i]]].pb(ii(cnt[a[i]], p[i]));
    }
    vector<ll> dp(m, 0);
    forup(int, i, 0, m - 1)
    {
        if (i)
            dp[i] = dp[i - 1];
        for (auto k : qp[i])
            dp[i] = max(dp[i], dp[k.fi] + k.se);
    }
    cout << dp[m - 1];
    return 0;
}