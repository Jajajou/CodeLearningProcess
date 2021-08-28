/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "group" //pls dont forget your task's name
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
int n(0), tracker_ir(0);
vector<ii> a, tracker;
vector<ll> x, y;

bool badLine(int a, int b, int c)
{
    return (x[a] - x[c]) * (y[c] - y[b]) < (x[b] - x[c]) * (y[c] - y[a]);
}

void add(ll _x, ll _y)
{
    x.pb(_x), y.pb(_y);
    while (x.size() >= 3 && badLine(x.size() - 3, y.size() - 2, y.size() - 1))
        x.erase(x.end() - 2), y.erase(y.end() - 2);
}

ll get(int k)
{
    if (tracker_ir == x.size())
        tracker_ir = x.size() - 1;
    while (tracker_ir < x.size() - 1 && x[tracker_ir + 1] * k + y[tracker_ir + 1] < x[tracker_ir] * k + y[tracker_ir])
        ++tracker_ir;
    return x[tracker_ir] * k + y[tracker_ir];
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    a.resize(n, {0, 0});
    for (auto &[_a, _b] : a)
        cin >> _a >> _b;
    sort(allVi(a));
    for (ii v : a)
    {
        while (!tracker.empty() && tracker.back().se <= v.se)
            tracker.pop_back();
        tracker.pb(v);
    }
    ll res(0);
    add(tracker[0].se, res);
    forup(int, i, 0, tracker.size() - 1)
    {
        res = get(tracker[i].fi);
        if (i < tracker.size() - 1)
            add(tracker[i + 1].se, res);
    }
    cout << res;
    return 0;
}