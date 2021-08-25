/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "lfr" //pls dont forget your task's name
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
int n(0), m(0), u(0), v(0);
bool visited[maxn];
vector<int> G[maxn], rG[maxn], depth, path;
map<ii, bool> cp;
stack<int> topoNum;

void dfs(int u)
{
    visited[u] = 1;
    for (int v : G[u])
    {
        if (!visited[v])
        {
            depth[v] = depth[u] + 1;
            path[v] = u;
            dfs(v);
        }
    }
    topoNum.push(u);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    depth.resize(n + 1, 0);
    path.resize(n + 1, 0);
    while (cin >> u >> v)
    {
        if (cp[ii(u, v)])
            continue;
        cp[ii(u, v)] = 1;
        G[u].pb(v);
        rG[v].pb(u);
    }
    dfs(1);
    if (!visited[n])
        return cout << "IMPOSSIBLE", 0;
    while (!topoNum.empty())
    {
        int v(topoNum.top());
        topoNum.pop();
        for (int u : rG[v])
            if (depth[v] < depth[u] + 1)
                depth[v] = depth[u] + 1, path[v] = u;
    }
    vector<int> res;
    while (n - 1)
        res.pb(n), n = path[n];
    res.pb(1);
    cout << res.size() << '\n';
    reverse(res.begin(), res.end());
    for (int ans : res)
        cout << ans << ' ';
    return 0;
}