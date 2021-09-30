/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "walk" //pls dont forget your task's name
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
const ll MOD = 1e9 + 7;
int n(0);
ll k(0);
vector<vector<ll>> base;

template <class val>
val mul(val a, val b, val m)
{
    if (!b)
        return 0;
    if (!(b - 1))
        return a;
    return b & 1 ? (mul(a, b >> 1, m) * 2 + a) % m : (mul(a, b >> 1, m) * 2) % m;
}

class matrix
{
public:
    vector<vector<ll>> adj;
    matrix(int ok = 0)
    {
        adj.resize(n, vector<ll>(n, 0));
        forup(int, i, 0, n - 1) forup(int, j, 0, n - 1) adj[i][j] = ok ? (i == j) : 0;
    }
    matrix(vector<vector<ll>> &tmp) { adj = tmp; }
    matrix operator%(const ll &k)
    {
        vector<vector<ll>> tmp(n, vector<ll>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tmp[i][j] = adj[i][j] % k;
        return matrix(tmp);
    }
    matrix operator*(const matrix &mm)
    {
        vector<vector<ll>> tmp(n, vector<ll>(n, 0));
        forup(int, i, 0, n - 1) forup(int, j, 0, n - 1)
        {
            tmp[i][j] = [&]()
            {
                ll cp(0);
                forup(int, k, 0, n - 1) cp = ((cp % MOD) + (mul(adj[i][k] % MOD, mm.adj[k][j] % MOD, MOD) % MOD)) % MOD;
                return cp;
            }();
        }
        return matrix(tmp) % MOD;
    }
    matrix operator^=(const ll &k)
    {
        if (k <= 1)
            return matrix(1);
        matrix res = *this ^= (k >> 1);
        return k & 1 ? res * res * matrix(1) : res * res;
    }
    ll sum()
    {
        ll res(0);
        forup(int, i, 0, n - 1) forup(int, j, 0, n - 1)(res += adj[i][j]) %= MOD;
        return res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> k;
    base.resize(n, vector<ll>(n, 0));
    forup(int, i, 0, n - 1) forup(int, j, 0, n - 1) cin >> base[i][j];
    matrix res = matrix(base);
    res ^= k;
    cout << res.sum();
    return 0;
}