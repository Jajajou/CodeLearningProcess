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
struct yes
{
    ll a, b, p;
    bool operator<(const yes &p) { return b < p.b; }
};
istream &operator>>(istream &cin, yes &x)
{
    ll l, r, c;
    cin >> l >> r >> c;
    return x = {l, r, c}, cin;
}
ostream &operator<<(ostream &cout, const yes &x)
{
    return cout << x.a << x.b << x.p, cout;
}

int check(vector<yes> arr, int pos)
{
    fordown(int, i, pos - 1, 0)
    {
        if (arr[i].b < arr[pos].a)
            return i;
    }
    return -1;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;
    vector<yes> c(n);
    for (yes &v : c)
        cin >> v;
    sort(c.begin(), c.end());
    vector<ll> dp(n, 0);
    dp[0] = c[0].p;
    forup(int, i, 1, n - 1)
    {
        ll tmp = c[i].p;
        int cp(check(c, i));
        if (cp != -1)
            tmp += dp[cp];
        dp[i] = max(tmp, dp[i - 1]);
    }
    cout << dp[n - 1];
    return 0;
}