/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "pokemon" //pls dont forget your task's name
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
    return x >> (pos - 1) & 1;
}
template <class val>
val setBitVal(val pos, val x, val inp) { return (x == 1) ? inp |= (1 << (pos - 1)) : inp ^= (1 << (pos - 1)); }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
    Fin(name);
    Fout(name);
}
struct data
{
    int p, t, d;
} station[21];
int n(0), T(0), a[21][21], dp[21][1 << 20 + 1];

void read()
{
    scanf("%d %d", &n, &T);
    forup(int, i, 1, n) scanf("%d %d %d", &station[i].p, &station[i].t, &station[i].d), station[i].d = (station[i].d == -1) ? 4000 : station[i].d;
    forup(int, i, 1, n + 2) forup(int, j, 1, n + 2) scanf("%d", &a[i][j]);
    forup(int, i, 0, n) forup(int, state, 0, (1 << n)) dp[i][state] = 4000;
}

void solve()
{
    int res(0), tracker(0);
    forup(int, state, 1, (1 << n) - 1)
    {
        int tmp(0);
        forup(int, i, 1, n) tmp += getBit(state, i) ? station[i].p : 0;
        int posCheck(__builtin_popcount(state));
        forup(int, i, 1, n)
        {
            if (!getBit(state, i))
                continue;
            if (posCheck == 1)
            {
                if (a[n + 1][i] + station[i].t + a[i][n + 2] <= T && a[n + 1][i] + station[i].t <= station[i].d)
                    dp[i][state] = a[n + 1][i] + station[i].t;
            }
            else
            {
                int tmpState(setBitVal(i, 0, state));
                forup(int, j, 1, n)
                {
                    if (!getBit(tmpState, j))
                        continue;
                    if (dp[j][tmpState] + a[j][i] + station[i].t + a[i][n + 2] <= T && dp[j][tmpState] + a[j][i] + station[i].t <= station[i].d)
                        dp[i][state] = min(dp[j][tmpState] + a[j][i] + station[i].t, dp[i][state]);
                }
            }
            if (dp[i][state] + a[i][n + 2] <= T && tmp >= res)
                res = tmp, tracker = state;
        }
    }
    printf("%d\n", res);
    forup(int, i, 1, n) if (getBit(tracker, i)) printf("%d ", i);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    return 0;
}