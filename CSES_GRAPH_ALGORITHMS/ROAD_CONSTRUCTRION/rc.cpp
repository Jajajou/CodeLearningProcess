/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "rc" // pls dont forget your task's name
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
#define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
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
struct DSU
{
    int n;
    vector<int> root, depth;
    void init(int _n)
    {
        n = _n;
        root.resize(n + 1);
        depth.resize(n + 1, 1);
        forup(int, i, 1, n) root[i] = i;
    }
    int findRoot(int u)
    {
        if (u != root[u])
            root[u] = findRoot(root[u]);
        return root[u];
    }
    int join(int u, int v)
    {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v)
            return -1;
        if (depth[u] > depth[v])
            swap(u, v);
        root[v] = u, depth[u] += depth[v];
        return u;
    }
} dsu;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), m(0), res(0);
    cin >> n >> m;
    dsu.init(n);
    forup(int, i, 1, m)
    {
        int u(0), v(0);
        cin >> u >> v;
        int x = dsu.join(u, v);
        if (x != -1)
            --n, maximize(res, dsu.depth[x]);
        cout << n << ' ' << res << endl;
    }
    return 0;
}