/* 
#include <bits/stdc++.h>
#define name "mixup2" //pls dont forget your task's name
#define maxn 101001
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
ll f[70000][17], tong = 0;

int TTD(int x)
{
    return x > 0 ? x : -x;
}

int main()
{
    Fin(name);
    Fout(name);
    int n, M, a[17], b[17], chay = 1;
    tong = 0;
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        f[0][i] = 1;
    b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] * 2;
        chay = chay + b[i];
    }
    for (int i = 1; i <= chay; i++)
    {
        int t[n], m = i;
        for (int j = 0; j < n; j++)
        {
            t[j] = m % 2;
            m = m / 2;
        }
        for (int j = 0; j < n; j++)
        {
            f[i][j] = 0;
            if (b[j] == i)
                f[i][j] = 1;
            else if (t[j] != 0)
            {
                for (int k = 0; k < n; k++)
                    if (TTD(a[j] - a[k]) > M)
                        f[i][j] += f[i - b[j]][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
        tong += f[chay][i];
    printf("%lld", tong);
} 2019 ver */

/* 2021 ver
   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "mixup2" //pls dont forget your task's name
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
val getBit(val x, val pos) { return x >> pos & 1; }
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << (pos - 1)) : inp &= ~(1 << (pos - 1)); }

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), k(0);
ll *a, **dp;

void read()
{
    scanf("%d %d\n", &n, &k);
    a = new ll[n];
    dp = new ll *[n];
    forup(int, i, 0, n - 1)
    {
        dp[i] = new ll[(1 << n) + 1];
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    forup(int, i, 0, n - 1) forup(int, state, 0, (1 << n)) dp[i][state] = 0;
}

void solve()
{
    forup(int, i, 0, n - 1) dp[i][1 << i] = 1;
    forup(int, state, 0, (1 << n) - 1) forup(int, i, 0, n - 1)
    {
        if (!getBit(state, i))
            continue;
        forup(int, j, 0, n - 1) if (getBit(state, j) && abs(a[i] - a[j]) > k)
            dp[i][state] += dp[j][state ^ (1 << i)];
    }
    ll res(0);
    forup(int, i, 0, n - 1) res += dp[i][(1 << n) - 1];
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    forup(int, i, 0, n - 1) delete[] dp[i];
    delete[] a, dp;
    return 0;
}