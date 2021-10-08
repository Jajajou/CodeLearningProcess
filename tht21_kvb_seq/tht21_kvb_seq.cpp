/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "tht21_kvb_seq" //pls dont forget your task's name
#define maxn int(1e5) + 15
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
int n(0);
ll ar[maxn], pref1[maxn], pref2[maxn], res(-ll(1e20));
map<ll, int> pos1, pos2;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 1, n)
    {
        cin >> ar[i];
        pref1[i] = pref1[i - 1] + ar[i];
        pos1[ar[i]] = 0;
        pos2[ar[i]] = n + 1;
    }
    forup(int, i, 1, n) maximize(pos1[ar[i]], i);
    fordown(int, i, n, 1) minimize(pos2[ar[i]], i), pref2[i] = pref2[i + 1] + ar[i];
    forup(int, i, 1, n) if (pos1[ar[i]] > i) maximize(res, pref1[pos1[ar[i]]] - pref1[i - 1]);
    fordown(int, i, n, 1) if (pos2[ar[i]] < i) maximize(res, pref2[pos2[ar[i]]] - pref2[i + 1]);
    cout << (res != -ll(1e20) ? res : *max_element(ar + 1, ar + n + 1));
    return 0;
}