/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "trt" //pls dont forget your task's name
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
int n(0), *arr, **dp, res(0);
bool **tracking;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif

    function<int(int, int)> DP = [&DP](int L, int R)
    {
        if (dp[L][R])
            return dp[L][R];
        int y(n - (R - L));
        if (L == R)
            return y * arr[L];
        int cp1(y * arr[L] + DP(L + 1, R)), cp2(y * arr[R] + DP(L, R - 1));
        int res(max(cp1, cp2));
        dp[L][R] = res;
        tracking[L][R] = (cp1 < cp2);
        return res;
    };

    cin >> n;
    arr = new int[n + 1];
    dp = new int *[n + 1];
    tracking = new bool *[n + 1];
    forup(int, i, 0, n) tracking[i] = new bool[n + 1], dp[i] = new int[n + 1];
    forup(int, i, 1, n) cin >> arr[i];
    forup(int, i, 0, n) forup(int, j, 0, n) dp[i][j] = 0;

    cout << DP(1, n) << endl;
    int i(1), j(n);
    while (i <= j)
        cout << (tracking[i][j] ? j-- : i++) << endl;

    forup(int, i, 0, n - 1) delete[] dp[i], tracking[i];
    delete[] arr, dp, tracking;
    return 0;
}