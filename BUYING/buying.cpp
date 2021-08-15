/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "buying" //pls dont forget your task's name
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
struct Store
{
    int x, y, z;
    const void define() { y -= x, z -= x; }
    bool operator<(const Store m)
    {
        return y - z < m.y - m.z;
    }
};
int n(0);
Store *p;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    p = new Store[n + 1];
    ll sumA(0);
    forup(int, i, 1, n) cin >> p[i].x >> p[i].y >> p[i].z, sumA += p[i].x, p[i].define();
    sort(p + 1, p + 1 + n);
    vector<vector<ll>> base(2, vector<ll>(n + 1, -1)), dp(2, vector<ll>(n + 1));
    vector<ll> minL(n + 1, LONG_MAX), minR(n + 1, LONG_MAX);
    base[0][0] = 0;
    forup(int, i, 1, n)
    {
        forup(int, j, 0, i)
        {
            dp[0][j] = LONG_MAX;
            if (base[0][j] != -1)
                dp[0][j] = base[0][j];
            if (j && base[0][j - 1] != -1)
                dp[0][j] = min(dp[0][j], base[0][j - 1] + p[i].y - j + 1);
            minL[i] = min(minL[i], dp[0][j]);
            if (dp[0][j] == LONG_MAX)
                dp[0][j] = -1;
        }
        forup(int, j, 0, i)
            base[0][j] = dp[0][j];
    }
    base[1][0] = 0;
    forup(int, i, 1, n)
    {
        forup(int, j, 0, i)
        {
            dp[1][j] = LONG_MAX;
            if (base[1][j] != -1)
                dp[1][j] = base[1][j];
            if (j && base[1][j - 1] != -1)
                dp[1][j] = min(dp[1][j], base[1][j - 1] + p[i].z - j + 1);
            minR[i] = min(minR[i], dp[1][j]);
            if (dp[1][j] == LONG_MAX)
                dp[1][j] = -1;
        }
        forup(int, j, 0, i)
            base[1][j] = dp[1][j];
    }
    ll cp(LONG_MAX);
    forup(int, i, 1, n) cp = min({cp, minL[i], minR[i]});
    cout << sumA + cp;
    return 0;
}