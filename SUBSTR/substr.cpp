/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "substr" //pls dont forget your task's name
#define maxn 1000111
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
ll POW[maxn], hashT[maxn];

ll getHashT(int i, int j)
{
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    string T, P;
    cin >> T >> P;
    int lenT = T.size(), lenP = P.size();
    T = " " + T;
    P = " " + P;
    POW[0] = 1;
    for (int i = 1; i <= lenT; i++)
        POW[i] = (POW[i - 1] * base) % MOD;
    for (int i = 1; i <= lenT; i++)
        hashT[i] = (hashT[i - 1] * base + T[i] - 'a' + 1) % MOD;
    ll hashP = 0;
    for (int i = 1; i <= lenP; i++)
        hashP = (hashP * base + P[i] - 'a' + 1) % MOD;
    for (int i = 1; i <= lenT - lenP + 1; i++)
        if (hashP == getHashT(i, i + lenP - 1))
            printf("%d ", i);
    return 0;
}