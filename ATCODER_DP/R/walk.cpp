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

struct matrix
{
    ll mat[50][50];
    matrix(int id = 0)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                mat[i][j] = (id) ? (i == j) : (0);
            }
        }
    }
    matrix operator*(const matrix &other) const
    {
        matrix ans;
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                for (int t = 0; t < 50; t++)
                {
                    ans.mat[i][j] += mat[i][t] * other.mat[t][j];
                    if (ans.mat[i][j] > MOD)
                        ans.mat[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
};

matrix exp(matrix base, ll k)
{
    matrix ans(1);
    for (int i = 0; (1LL << i) <= k; i++)
    {
        if ((1LL << i) & k)
            ans = ans * base;
        base = base * base;
    }
    return ans;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    matrix base;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> base.mat[i][j];
    }
    matrix ans = exp(base, k);
    ll paths = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            paths = (paths + ans.mat[i][j]) % MOD;
    }
    cout << paths;
    return 0;
}