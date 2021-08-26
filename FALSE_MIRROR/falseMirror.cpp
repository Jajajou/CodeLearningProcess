/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "falseMirror" //pls dont forget your task's name
#define maxn 101001
#define elif else if
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
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n, monsters[20], damage[(1 << 20)], dp[(1 << 20)];

int DP(int mask)
{
    if (dp[mask] != -1)
        return dp[mask];
    int &res = dp[mask];
    forup(int, i, 0, n - 1)
    {
        bool ok(0);
        forup(int, j, 0, 2) if ((mask & (1 << ((i + j) % n))) == 0) ok = 1;
        if (!ok)
            continue;
        int mask2(mask);
        forup(int, j, 0, 2) mask2 |= (1 << ((i + j) % n));
        int k = DP(mask2) + damage[mask2];
        if (res == -1 || k < res)
            res = k;
    }
    return res != -1 ? res : 0;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 0, n - 1) cin >> monsters[i];
    forup(int, mask, 0, (1 << n) - 1)
    {
        damage[mask] = 0;
        forup(int, i, 0, n - 1) if ((mask & (1 << i)) == 0) damage[mask] += monsters[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << DP(0);
    return 0;
}