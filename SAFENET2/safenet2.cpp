/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "safenet2" //pls dont forget your task's name
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
struct DSU
{
    int n;
    vector<int> root;
    void init(int _n)
    {
        n = _n;
        root.resize(n + 1);
    }
    int findRoot(int u)
    {
        if (u != root[u])
            root[u] = findRoot(root[u]);
        return root[u];
    }
};
DSU dsu;
int n(0), m(0), active[maxn];
bool visited[maxn];
vector<int> G[maxn], st;

void visit(int u)
{
    visited[u] = 1;
    dsu.root[u] = u;
    st.pb(u);
    for (int v : G[u])
        if (visited[v])
        {
            v = dsu.findRoot(active[v]);
            while (st.back() != v)
            {
                dsu.root[dsu.findRoot(st.back())] = v;
                st.pop_back();
            }
        }
    for (int v : G[u])
        if (!visited[v])
        {
            active[u] = v;
            visit(v);
        }
    if (st.back() == u)
        st.pop_back();
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    if (m == 0)
        return cout << 1, 0;
    dsu.init(n);
    for (int i(0), v, u; i < m && cin >> u >> v; ++i)
        G[u].pb(v), G[v].pb(u);
    forup(int, i, 1, n) if (!visited[i]) visit(i);
    vector<int> res(n + 1, 0);
    forup(int, i, 1, n) res[dsu.findRoot(i)]++;
    cout << 1 + *max_element(res.begin(), res.end());
    return 0;
}