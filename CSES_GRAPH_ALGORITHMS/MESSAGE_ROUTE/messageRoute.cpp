/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "messageRoute" //pls dont forget your task's name
#define maxn 101001
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
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), m(0), path[maxn];
vector<int> G[int(2e5) + 25];

void bfs()
{
    path[1] = -1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u(q.front());
        q.pop();
        for (int v : G[u])
            if (!path[v])
                path[v] = u, q.push(v);
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
    bfs();
    if (!path[n])
        return cout << "IMPOSSIBLE", 0;
    vector<int> res;
    while (n + 1)
    {
        res.pb(n);
        n = path[n];
    }
    cout << res.size() << '\n';
    fordown(int, i, res.size() - 1, 0) cout << res[i] << ' ';
    return 0;
}