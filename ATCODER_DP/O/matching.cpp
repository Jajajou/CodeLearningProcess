/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "matching" //pls dont forget your task's name
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
const int MOD = 1e9 + 7;
int n(0);
vector<int> adj;
vector<vector<int>> dp;

int DP(int pos, int mask)
{
    if (pos == n)
        return __builtin_popcount(mask) == n;
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int &res = dp[pos][mask] = 0;
    forup(int, i, 0, n - 1) if (adj[pos] && getBit(mask, i) == 0 && getBit(adj[pos], i) == 1)(res += DP(pos + 1, mask | (1 << i))) %= MOD;
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    adj.resize(n, 0);
    dp.resize(n, vector<int>((1 << n), -1));
    for (int i(0); i < n; ++i)
        for (int j(0), x; j < n; ++j)
        {
            cin >> x;
            if (x == 1)
                adj[i] |= (1 << j);
        }
    cout << DP(0, 0);
    return 0;
}