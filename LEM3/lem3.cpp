/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "lem3" //pls dont forget your task's name
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
val getBit(val x, val pos) { return x >> pos & 1; }
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << (pos - 1)) : inp &= ~(1 << (pos - 1)); }

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0);
ll **a, **base;

void read()
{
    scanf("%d", &n);
    a = new ll *[n];
    base = new ll *[n];
    forup(int, i, 0, n - 1)
    {
        a[i] = new ll[n];
        base[i] = new ll[(1 << n)];
        forup(int, j, 0, n - 1) scanf("%lld", &a[i][j]);
    }
    forup(int, i, 0, n - 1) forup(int, state, 0, (1 << n) - 1) base[i][state] = 0;
}

void solve()
{
    function<ll(int, int)> dp = [&dp](int i, int state)
    {
        if (state == 0)
            return 0LL;
        ll &res = base[i][state];
        if (!res)
        {
            res = LONG_MAX;
            forup(int, j, 0, n - 1) if (getBit(state, j)) res = min(res, dp(j, state ^ (1 << j)) + a[j][i]);
        }
        return res;
    };

    ll res(LONG_MAX);
    forup(int, i, 0, n - 1) res = min(res, dp(i, (1 << n) - 1));
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    forup(int, i, 0, n - 1) delete[] a[i];
    delete[] a;
    forup(int, i, 0, n - 1) delete[] base[i];
    delete[] base;
    return 0;
}