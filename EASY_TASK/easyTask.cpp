/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "easyTask" //pls dont forget your task's name
#define maxn int(1e6)
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
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
bool notPrime[maxn];
void seive()
{
    notPrime[1] = 1;
    forup(int, i, 2, int(sqrt(maxn))) if (!notPrime[i])
    {
        for (int j(i * i); j <= maxn; j += i)
            notPrime[j] = 1;
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    seive();
    int n(0);
    cin >> n;
    vector<ll> f(n + 1, 0);
    for (int i(1), x(0); i <= n && cin >> x; ++i)
        f[i] = f[i - 1] + (ll)(x);
    ll minTracker(LONG_MAX), res(LONG_MIN);
    forup(int, i, 1, n) if (!notPrime[i])
        minTracker = min(minTracker, f[i - 1]),
        res = max(res, f[i] - minTracker);
    cout << res;
    return 0;
}