/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "countingTilings" //pls dont forget your task's name
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
int dp[1001][1 << 11];

void calState(int i, int currentMask, int nextMask, int line, vector<int> &state)
{
    if (i == line + 1)
        return (void)(state.pb(nextMask));
    if ((currentMask & (1 << i)))
        calState(i + 1, currentMask, nextMask, line, state);
    if ((i - line) && ((currentMask & (1 << i)) == 0) && ((currentMask & (1 << (i + 1))) == 0))
        calState(i + 2, currentMask, nextMask, line, state);
    if ((currentMask & (1 << i)) == 0)
        calState(i + 1, currentMask, nextMask + (1 << i), line, state);
}

int DP(int i, int currentMask, int line, int collumn)
{
    if (i == collumn + 1)
        if (!currentMask)
            return 1;
        else
            return 0;
    if (dp[i][currentMask] + 1)
        return dp[i][currentMask];
    vector<int> vecState;
    calState(1, currentMask, 0, line, vecState);
    int res(0);
    for (int state : vecState)
        (res += DP(i + 1, state, line, collumn)) %= maxn;
    return dp[i][currentMask] = res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << DP(1, 0, n, m);
    return 0;
}