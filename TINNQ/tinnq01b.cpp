/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "tinnq01b" // pls dont forget your task's name
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
int n(0);
int a[int(1e5) + 51];

namespace sub1
{
    int lastPos(1), len[int(1e5) + 51];
    void solve()
    {
        vector<int> ans;
        forup(int, i, 1, n)
        {
            len[i] = 1;
            forup(int, j, 1, i - 1) if (a[i] % a[j] == 0 && len[j] + 1 > len[i])
                len[i] = len[j] + 1;
            if (len[i] > ans.size())
                ans.pb(i);
        }
        for (int v : ans)
            cout << a[v] << ' ';
    }
}

namespace sub2
{
    int res(0), x(0);
    vector<int> dp;
    function<int(vector<int> &, int)> bs = [&bs](vector<int> &dp, int cp)
    {
        bool ok(0);
        int l(0), r(dp.size() - 1), res(0);
        while (l <= r)
        {
            int mid((l + r) / 2);
            if (cp % dp[mid] == 0)
                ok = 1, r = mid - 1, res = mid;
            else
                r;
        }
        return l;
    };
    forup(int, i, 1, n)
    {
        cin >> x;
        int p = bs(dp, x);
        if (p == res)
        {
            ++res;
            dp[res] = x;
        }
        else
            dp[p] = min(dp[p], x);
    }
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 1, n) cin >> a[i];
    if (n <= 1000)
        sub1::solve();
    elif (n <= 10000)
        sub2::solve();

    return 0;
}