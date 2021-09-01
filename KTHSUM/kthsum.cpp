/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "kthsum" //pls dont forget your task's name
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
typedef tuple<ll, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), k(0);
ll a[int(1e5)], b[int(1e5)];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> k;
    for (int i(0); i < n; ++i)
        cin >> a[i];
    for (int i(0); i < n; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    pri_q<iii, vector<iii>, greater<iii>> pq;
    set<ii> checked;
    checked.insert({0, 0});
    pq.emplace(a[0] + b[0], 0, 0);
    bool ok(1);
    while (k && ok)
    {
        auto [sum, i, j] = pq.top();
        pq.pop();
        cout << sum << ' ';
        ok = 0;
        if (i + 1 < n)
        {
            if (checked.find({i + 1, j}) == checked.end())
            {
                checked.insert({i + 1, j});
                pq.emplace(a[i + 1] + b[j], i + 1, j);
            }
            ok = 1;
        }
        if (j + 1 < n)
        {
            if (checked.find({i, j + 1}) == checked.end())
            {
                checked.insert({i, j + 1});
                pq.emplace(a[i] + b[j + 1], i, j + 1);
            }
            ok = 1;
        }
        --k;
    }
    return 0;
}