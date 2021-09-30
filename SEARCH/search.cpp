/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "search" //pls dont forget your task's name
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
const int base = 131;
const ll MOD = 1000000007;
int n(0), m(0), k(0), hashA(0);
vector<int> a, b, hashB, POW;

void add(int &a, int b)
{
    a += b;
    if (a >= k)
        a -= k;
}

int getHash(int l, int r) { return (hashB[r] - hashB[l - 1] * POW[r - l + 1] + MOD * MOD) % MOD; }

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m >> k;
    a.resize(n + 1, 0);
    b.resize(m + 1, 0);
    hashB.resize(m + 1, 0);
    POW.resize(max(n, m) + 1, 0);
    POW[0] = 1;
    forup(int, i, 1, POW.size() - 1) POW[i] = (POW[i - 1] * base) % MOD;
    forup(int, i, 0, n - 1) cin >> a[i];
    forup(int, i, 0, m - 1) cin >> b[i];
    fordown(int, i, n, 1) a[i] -= a[i - 1], add(a[i], k);
    fordown(int, i, m, 1) b[i] -= b[i - 1], add(b[i], k);
    --n, --m;
    forup(int, i, 1, n) hashA = (hashA * base + a[i]) % MOD;
    forup(int, i, 1, m) hashB[i] = (hashB[i - 1] * base + b[i]) % MOD;
    bool ok(0);
    forup(int, i, 1, m - n + 1) if (hashA == getHash(i, i + n - 1)) ok = 1, cout << i << ' ';
    if (!ok)
        cout << 0;
    return 0;
}