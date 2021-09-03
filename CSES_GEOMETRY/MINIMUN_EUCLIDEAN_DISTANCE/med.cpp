/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "med" //pls dont forget your task's name
#define maxn int(2e5) + 25
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
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
istream &operator>>(istream &cin, ii &x)
{
    ll a, b;
    cin >> a >> b;
    return x = {a, b}, cin;
}
ii p[maxn];
int n(0);
ll res(LONG_MAX);
ll sqr(ll x) { return x * x; }
ll dist(ii a, ii b) { return ll(sqr(a.fi - b.fi) + sqr(a.se - b.se)); }
bool isLeft[maxn];

void solve(vector<int> qL, vector<int> qR)
{
    int k(qL.size());
    if (k == 1)
        return;
    vector<int> l_L, l_R, r_L, r_R;
    forup(int, i, 0, k - 1) if (i < int(k / 2))
    {
        l_L.pb(qL[i]), isLeft[qL[i]] = 1;
    }
    else
    {
        r_L.pb(qL[i]), isLeft[qL[i]] = 0;
    }
    for (int id : qR)
    {
        if (isLeft[id])
            l_R.pb(id);
        else
            r_R.pb(id);
    }
    solve(l_L, l_R);
    solve(r_L, r_R);
    vector<int> track;
    ll cp(p[l_L.back()].fi);
    for (int id : qR)
        if (sqr(p[id].fi - cp) < res)
            track.pb(id);
    for (int i(0); i < (int)(track.size()); ++i)
        for (int j(i + 1); j < (int)(track.size()) && sqr(p[track[i]].se - p[track[j]].se) < res; ++j)
            minimize(res, dist(p[track[i]], p[track[j]]));
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    vector<int> sortX, sortY;
    for (int i(0); i < n && cin >> p[i]; ++i)
        sortX.pb(i), sortY.pb(i);
    sort(allVi(sortX), [](int &a, int &b)
         { return p[a].fi < p[b].fi; });
    sort(allVi(sortY), [](int &a, int &b)
         { return p[a].se < p[b].se; });
    solve(sortX, sortY);
    cout << res;
    return 0;
}