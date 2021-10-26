/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "hamilton" // pls dont forget your task's name
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
bool ok(0);
int n(0), m(0), cnt(0), path[202];
vector<int> G[202];

void dfs(int u)
{
    if (ok)
        return;
    ++cnt;
    for (int v : G[u])
    {
        if (!path[v] && cnt < n)
        {
            path[v] = u;
            dfs(v);
            path[v] = 0;
            --cnt;
        }
        else if (v == 1 && cnt == n)
        {
            ok = 1;
            vector<int> res;
            while (u != -1)
            {
                res.pb(u);
                u = path[u];
            }
            for (int i = (int)res.size() - 1; i >= 0; i--)
                cout << res[i] << ' ';
            cout << 1;
            return;
        }
        if (ok)
            return;
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    int u(0), v(0);
    while (cin >> u >> v)
        G[u].pb(v), G[v].pb(u);
    path[1] = -1;
    dfs(1);
    if (ok == 0)
        return cout << -1, 0;
}