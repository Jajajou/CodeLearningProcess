/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "binladen" // pls dont forget your task's name
#define maxn int(1e5)
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
int n(0), m(0), w[4445][11], d[2222 * 10 + 1];
vector<vector<ii>> adj;
int hashh(int a, int b) { return (a - 1) * m + b; }

void dijkstra()
{
    forup(int, i, 0, n *m) d[i] = INT_MAX;
    d[0] = 0;
    pri_q<ii, vector<ii>, greater<ii>> mq;
    mq.push({d[0], 0});
    while (!mq.empty())
    {
        auto [du, u] = mq.top();
        mq.pop();
        if (d[u] != du)
            continue;
        for (auto [dv, v] : adj[u])
            if (d[v] > du + dv)
                mq.push({(d[v] = du + dv), v});
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    adj.resize(n * m + 1);
    forup(int, i, 1, 2 * n) forup(int, j, 1, m - 1 + (i & 1)) cin >> w[i][j];
    forup(int, i, 1, n) forup(int, j, 1, m)
    {
        int p(hashh(i, j));
        if (i != n)
            adj[p].pb({w[2 * i + 1][j], hashh(i + 1, j)});
        if (i != 1)
            adj[p].pb({w[2 * i - 1][j], hashh(i - 1, j)});
        if (j != m)
            adj[p].pb({w[2 * i][j], hashh(i, j + 1)});
        if (j != 1)
            adj[p].pb({w[2 * i][j - 1], hashh(i, j - 1)});
    }
    forup(int, j, 1, m) adj[0].pb({w[1][j], j});
    dijkstra();
    cout << d[n * m];
    return 0;
}