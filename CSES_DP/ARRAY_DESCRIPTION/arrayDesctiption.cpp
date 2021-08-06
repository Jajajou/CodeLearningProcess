/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "arrayDesctiption" //pls dont forget your task's name
#define maxn int(1e9) + 7
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
    int n(0), m(0);
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (int &v : arr)
        cin >> v;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (arr[0])
        dp[0][arr[0]] = 1;
    else
        fill(dp[0].begin(), dp[0].end(), 1);
    forup(int, i, 1, n - 1)
    {
        if (arr[i])
            (dp[i][arr[i]] += [&](int x)
             {
                 int res(0);
                 for (int k : {x - 1, x, x + 1})
                     (res += (k >= 1 && k <= m) ? dp[i - 1][k] : 0) %= maxn;
                 return res;
             }(arr[i])) %= maxn;
        else
            forup(int, x, 1, m) for (int k : {x - 1, x, x + 1})(dp[i][x] += (k >= 1 && k <= m) ? dp[i - 1][k] : 0) %= maxn;
    }
    int res(0);
    forup(int, i, 1, m)(res += dp[n - 1][i]) %= maxn;
    cout << res;
    return 0;
}