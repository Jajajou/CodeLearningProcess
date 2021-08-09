/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "c11seq2" //pls dont forget your task's name
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
    int n(0), k(0), m(0);
    cin >> n >> k;
    vector<ii> c(n + 1);
    c[0].fi = c[0].se = INT_MIN;
    vector<int> inArr(k + 1);
    forup(int, i, 1, n) cin >> c[i].fi, c[i].se = i;
    sort(c.begin(), c.end());
    cin >> m;
    forup(int, i, 1, k) cin >> inArr[i];
    //dp
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1LL;
    forup(int, i, 1, n) forup(int, j, 0, i) if (j == 0 || j == i)
        dp[j][i] = 1LL;
    else dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
    //arr mth
    vector<int> taken(k + 1, 0);
    int pos(0);
    forup(int, i, 1, k)
    {
        forup(int, j, 1, n) if (c[j].se > taken[i - 1])
        {
            if (dp[k - i][n - c[j].se] < m)
                m -= dp[k - i][n - c[j].se];
            else
            {
                taken[i] = c[j].se;
                cout << c[j].fi << ' ';
                break;
            }
        }
    }
    cut;
    //arr kth
    ll res(1LL);
    vector<int> inArrPos(k + 1, 0);
    forup(int, i, 1, k) forup(int, j, 1, n) if (inArr[i] == c[j].fi) inArrPos[i] = c[j].se;
    forup(int, i, 1, k) forup(int, j, 1, n)
    {
        if (c[j].fi == inArr[i])
            break;
        res += c[j].se > inArrPos[i - 1] ? dp[k - i][n - c[j].se] : 0;
    }
    cout << res;
    return 0;
}