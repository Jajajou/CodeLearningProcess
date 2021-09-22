/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "fwater" //pls dont forget your task's name
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

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), res(0);
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INT_MAX));
    vector<int> d(n + 1, INT_MAX);
    d[0] = 0;
    vector<bool> visited(n + 1, 0);
    for (int i(1), w(0); i <= n && cin >> w; ++i)
        adj[0][i] = adj[i][0] = w;
    forup(int, i, 1, n) forup(int, j, 1, n)
    {
        cin >> adj[i][j];
        if (i == j)
            adj[i][j] = INT_MAX;
    }
    forup(int, i, 0, n)
    {
        int curr(0), minVal(INT_MAX);
        forup(int, u, 0, n) if (!visited[u] && minVal > d[u]) minVal = d[u], curr = u;
        res += minVal, visited[curr] = 1;
        forup(int, u, 0, n) if (!visited[u] && d[u] > adj[curr][u]) d[u] = adj[curr][u];
    }
    cout << res;
    return 0;
}