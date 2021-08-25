/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "sushi" //pls dont forget your task's name
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
int n, cnt[4] = {0, 0, 0, 0};
double dp[303][303][303];

double DP(int a, int b, int c)
{
    if (dp[a][b][c])
        return dp[a][b][c];
    if (a == 0 && b == 0 && c == 0)
        return dp[a][b][c] = 0;
    double &res = dp[a][b][c] = 0;
    double k = (double)(n) / (double)(a + b + c);
    if (a > 0)
        res += (DP(a - 1, b, c) + k) / (double)(a + b + c) * a;
    if (b > 0)
        res += (DP(a + 1, b - 1, c) + k) / (double)(a + b + c) * b;
    if (c > 0)
        res += (DP(a, b + 1, c - 1) + k) / (double)(a + b + c) * c;
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    for (int i(0), x(0); i < n && cin >> x; ++i)
        ++cnt[x];
    printf("%0.9lf", DP(cnt[1], cnt[2], cnt[3]));
    return 0;
}