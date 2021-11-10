/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "qbbuild" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
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
// #define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
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
const int inf = 1e9;
int n, id[4], a[101][101];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    scanf("%d", &n);
    for (int i = 0; i < 4; ++i)
        scanf("%d", &id[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                a[i][j] = inf;
            else
                a[i][j] = 0;
    int u, v, c;
    while (scanf("%d%d%d", &u, &v, &c) != EOF)
    {
        minimize(a[u][v], c);
        minimize(a[v][u], c);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                minimize(a[i][j], a[i][k] + a[k][j]);
    int res = inf;
    sort(id, id + 4);
    do
    {
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                minimize(res, a[u][id[0]] + a[u][id[1]] + a[v][id[2]] + a[v][id[3]] + a[u][v]);
    } while (next_permutation(id, id + 4));
    printf("%d\n", res);
    return 0;
}