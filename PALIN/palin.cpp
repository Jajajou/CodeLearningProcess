/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "palin" //pls dont forget your task's name
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
int dp[5001][5001], n(0);
string s(""), res("");

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> s;
    s = " " + s;
    forup(int, k, 1, n - 1) forup(int, i, 1, n - k)
    {
        int j(i + k);
        dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;
    }
    cout << dp[1][n] << endl;
    int i(1), j(n), cp[n + 1], k(0);
    while (dp[i][j])
    {
        if (s[i] == s[j])
            ++i, --j, cp[++k] = 0;
        else if (dp[i][j] == dp[i + 1][j] + 1)
            ++i, cp[++k] = 2;
        else
            --j, cp[++k] = 1;
    }
    forup(int, t, i, j) res += s[t];
    while (k)
    {
        if (cp[k] == 0)
            res = s[--i] + res + s[++j];
        if (cp[k] == 1)
            ++j, res = s[j] + res + s[j];
        if (cp[k] == 2)
            --i, res = s[i] + res + s[i];
        --k;
    }
    cout << res;
    return 0;
}