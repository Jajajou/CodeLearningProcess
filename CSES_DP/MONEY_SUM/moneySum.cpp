/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "moneySum" //pls dont forget your task's name
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
    int n(0), target(0);
    cin >> n;
    vector<int> c(n);
    for (int &v : c)
        cin >> v, target += v;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, 0));
    dp[0][0] = 1;
    forup(int, i, 1, n) forup(int, j, 0, target)
    {
        dp[i][j] = dp[i - 1][j];
        if (j - c[i - 1] >= 0 && dp[i - 1][j - c[i - 1]])
            dp[i][j] = 1;
    }
    vector<int> res;
    forup(int, j, 1, target) if (dp[n][j]) res.pb(j);
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int v : res)
        cout << v << " ";
    return 0;
}