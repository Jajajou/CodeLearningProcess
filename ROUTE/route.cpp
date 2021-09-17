/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "route" //pls dont forget your task's name
#define maxn int(1e3) + 13
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
struct Data
{
    int val;
    string path;
    Data(int _val, string _path) : val(_val), path(_path) {}
};
Data min(Data a, Data b)
{
    if (a.val < b.val)
        return a;
    if (a.val > b.val)
        return b;
    return a.path < b.path ? a : b;
}
iii node;
int n(0), m(0), mX[2] = {-1, 0}, mY[2] = {0, -1}, a[maxn][maxn], dp[maxn][maxn], c2[maxn][maxn], c5[maxn][maxn];

Data z_path()
{
    memset(dp, -1, sizeof(dp));
    dp[n][m] = !a[n][m];
    pri_q<iii> pq;
    pq.push({n, m, dp[n][m]});
    while (!pq.empty())
    {
        auto [x, y, val] = pq.top();
        pq.pop();
        forup(int, k, 0, 1)
        {
            int u(x + mX[k]), v(y + mY[k]), _val(val || !a[u][v]);
            if (u < 1 || v < 1 || u > n || v > m)
                continue;
            if (dp[u][v] < _val)
                pq.push({u, v, dp[u][v] = _val});
        }
    }
    string trackerPath(n + m - 2, 'Z');
    bool ok(0);
    int res(dp[1][1]);
    if (res == 0)
        return Data(INT_MAX, trackerPath);
    for (int i(1), j(1), pos(0); pos < trackerPath.size(); ++pos)
    {
        if (i == n)
        {
            while (pos < trackerPath.size())
                trackerPath[pos++] = 'L';
            break;
        }
        if (j == m)
        {
            while (pos < trackerPath.size())
                trackerPath[pos++] = 'D';
            break;
        }
        ok |= !a[i][j];
        if (ok || dp[i + 1][j] >= dp[i][j + 1])
            trackerPath[pos] = 'D', ++i;
        else
            trackerPath[pos] = 'L', ++j;
    }
    return Data(res, trackerPath);
}

Data _path(int ar[maxn][maxn])
{
    memset(dp, int(1e6), sizeof(dp));
    dp[n][m] = ar[n][m];
    pri_q<iii> pq;
    pq.push({n, m, dp[n][m]});
    while (!pq.empty())
    {
        auto [x, y, val] = pq.top();
        pq.pop();
        forup(int, k, 0, 1)
        {
            int u(x + mX[k]), v(y + mY[k]), _val(dp[x][y] + ar[u][v]);
            if (u < 1 || v < 1)
                continue;
            if (dp[u][v] > _val)
                pq.push({u, v, dp[u][v] = _val});
        }
    }
    string trackerPath(n + m - 2, 'Z');
    int res(dp[1][1]);
    for (int i(1), j(1), pos(0); pos < trackerPath.size(); ++pos)
    {
        if (i == n)
        {
            while (pos < trackerPath.size())
                trackerPath[pos++] = 'L';
            break;
        }
        if (j == m)
        {
            while (pos < trackerPath.size())
                trackerPath[pos++] = 'D';
            break;
        }
        if (dp[i + 1][j] <= dp[i][j + 1])
            trackerPath[pos] = 'D', ++i;
        else
            trackerPath[pos] = 'L', ++j;
    }
    return Data(res, trackerPath);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    forup(int, i, 1, n) forup(int, j, 1, m) cin >> a[i][j];
    forup(int, i, 1, n) forup(int, j, 1, m)
    {
        if (!a[i][j])
        {
            c2[i][j] = c5[i][j] = int(1e5);
            continue;
        }
        for (int t(a[i][j]); t % 2 == 0; t /= 2)
            ++c2[i][j];
        for (int t(a[i][j]); t % 5 == 0; t /= 5)
            ++c5[i][j];
    }
    Data res = min(z_path(), min(_path(c2), _path(c5)));
    cout << res.val << '\n'
         << res.path;
    return 0;
}