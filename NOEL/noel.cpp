/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "noel" // pls dont forget your task's name
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
// #define Fin(name) freopen(name ".inp", "r", stdin)
#define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
#define Fout(name) freopen("D:\\C++\\NOEL\\" name ".out", "w", stdout)
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
int n(0), d(0);
vector<int> a;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> d;
    a.resize(2 * n);
    for (int &v : a)
        cin >> v;
    int res(0);
    forup(int, x, 1, 2 * n)
    {
        int id[2 * n + 1];
        bool exist[2 * n + 1];
        memset(exist, 0, sizeof(exist));
        forup(int, j, x, 2 * n - 1) id[a[j]] = j, exist[a[j]] = 1;
        vector<int> b;
        forup(int, i, 0, x - 1)
        {
            vector<int> cp;
            fordown(int, k, d, -d)
            {
                if (a[i] + k <= 0)
                    continue;
                if (!exist[a[i] + k])
                    continue;
                cp.pb(id[a[i] + k]);
            }
            sort(allVi(cp), greater<int>());
            for (int v : cp)
                b.pb(v);
        }
        int dp[(int)b.size() + 1], cp(0);
        for (int v : b)
        {
            int p(lower_bound(dp, dp + cp, v) - dp);
            if (p == cp)
                dp[cp++] = v;
            else
                minimize(dp[p], v);
        }
        maximize(res, cp);
    }
    cout << res;

    return 0;
}
