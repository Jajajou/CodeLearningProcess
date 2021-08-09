/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "rectangleCutting" //pls dont forget your task's name
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
    int w(0), h(0);
    cin >> w >> h;
    vector<vector<int>> dp(w + 1, vector<int>(h + 1));
    forup(int, i, 0, w) forup(int, j, 0, h)
    {
        dp[i][j] = i == j ? 0 : [&](int w, int h)
        {
            int res = int(1e7);
            forup(int, k, 1, w) res = min(res, dp[k][j] + dp[i - k][j] + 1);
            forup(int, k, 1, h) res = min(res, dp[i][k] + dp[i][j - k] + 1);
            return res;
        }(i - 1, j - 1);
    }
    cout << dp[w][h];
    return 0;
}