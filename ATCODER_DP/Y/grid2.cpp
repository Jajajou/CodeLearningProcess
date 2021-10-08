/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "grid2" //pls dont forget your task's name
#define maxn int(2e5) + 25
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
int h(0), w(0), n(0);
vector<ii> block;
const ll MOD(1e9 + 7);
vector<int> arr;
ll naturalNumInverse[maxn], factNumInverse[maxn], fact[maxn], dp[int(2e5) + 25];

void inverseOfNumber()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    forup(int, i, 2, int(2e5))
        naturalNumInverse[i] = naturalNumInverse[MOD % i] * (MOD - MOD / i) % MOD;
}
void inverseOfFactorial()
{
    factNumInverse[0] = factNumInverse[1] = 1;
    for (int i = 2; i <= int(2e5); i++)
        factNumInverse[i] = (naturalNumInverse[i] * factNumInverse[i - 1]) % MOD;
}

void factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= int(2e5); i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}

ll C(int n, int k)
{
    ll res = ((fact[n] * factNumInverse[k] % MOD) * (factNumInverse[n - k] % MOD)) % MOD;
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    inverseOfNumber();
    inverseOfFactorial();
    factorial();
    cin >> h >> w >> n;
    block.pb({h, w});
    for (int i(0), u, v; i < n && cin >> u >> v; ++i)
        block.pb({u, v});
    sort(allVi(block));
    forup(int, i, 0, n) dp[i] = C(block[i].fi + block[i].se - 2, block[i].fi - 1) % MOD;
    forup(int, i, 0, n - 1) forup(int, j, i + 1, n)
    {
        int dX(block[j].fi - block[i].fi), dY(block[j].se - block[i].se);
        if (dX < 0 || dY < 0)
            continue;
        (dp[j] -= C(dX + dY, dY) * dp[i]) %= MOD;
    }
    if (dp[n] < 0)
        dp[n] += MOD;
    cout << dp[n] % MOD;
    return 0;
}