/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "roundTripII" //pls dont forget your task's name
#define maxn int(2e5) + 25
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
int n(0), m(0), path[maxn >> 1], visited[maxn >> 1];
vector<int> G[maxn];

void dfs(int u)
{
    visited[u] = 1;
    for (int v : G[u])
    {
        if (visited[v] == 1)
        {
            path[v] = u;
            vector<int> res;
            res.pb(v);
            int f(path[v]);
            while (f - v)
            {
                res.pb(f);
                f = path[f];
            }
            res.pb(v);
            cout << res.size() << '\n';
            reverse(allVi(res));
            for (int ans : res)
                cout << ans << ' ';
            exit(0);
        }
        else if (!visited[v])
        {
            path[v] = u;
            dfs(v);
        }
    }
    visited[u] = 2;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int u(0), v(0);
    cin >> n >> m;
    while (cin >> u >> v)
        G[u].pb(v);
    forup(int, i, 1, n) if (!visited[i]) dfs(i);
    cout << "IMPOSSIBLE";
    return 0;
}