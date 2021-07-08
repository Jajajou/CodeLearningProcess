/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "rect9" //pls dont forget your task's name
#define maxn 1001
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

typedef long long ll;
typedef unsigned long long ull;
int n(0), m(0), a[maxn][maxn] = {{}}, res(0), height[maxn] = {};

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

void read()
{
    cin >> n >> m;
    forup(int, i, 1, n) forup(int, j, 1, m) cin >> a[i][j];
    height[0] = height[m + 1] = -1;
}

int checkPoint()
{
    int res(0);
    forup(int, j, 1, m)
    {
        int l = [&]() -> int
        {
            fordown(int, i, j - 1, 0) if (height[i] < height[j]) return i + 1;
            return -1;
        }();
        int r = [&]() -> int
        {
            forup(int, i, j + 1, m + 1) if (height[i] < height[j]) return i - 1;
            return -1;
        }();
        res = max(res, (r - l + 1) * height[j]);
    }
    return res;
}

void solve()
{
    forup(int, i, 1, n)
    {
        forup(int, j, 1, m) height[j] = (a[i][j] == 9) ? height[j] + 1 : 0;
        res = max(res, checkPoint());
    }
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
    return 0;
}