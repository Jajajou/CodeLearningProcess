/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "elevatorRides" //pls dont forget your task's name
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

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), x(0);
    cin >> n >> x;
    vector<int> arr(n, 0);
    for (int &v : arr)
        cin >> v;
    ii dp[1 << n];
    dp[0] = {0, x};
    forup(int, state, 1, ((1 << n) - 1))
    {
        dp[state] = {22, 0};
        forup(int, i, 0, n - 1) if (getBit(state, i))
        {
            ii cp(dp[state ^ (1 << i)]);
            if (cp.se + arr[i] > x)
            {
                ++cp.fi;
                cp.se = min(cp.se, arr[i]);
            }
            else
                cp.se += arr[i];
            dp[state] = min(dp[state], cp);
        }
    }
    cout << dp[((1 << n) - 1)].fi;
    return 0;
}