/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "qbschool" // pls dont forget your task's name
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
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), m(0);
vector<vector<ii>> adj;

void dijkstra()
{
    vector<ll> d(n + 1, LONG_MAX), c(n + 1, 0);
    d[1] = 0LL;
    c[1] = 1;
    pri_q<ii, vector<ii>, greater<ii>> mq;
    mq.push({d[1], 1});
    while (!mq.empty())
    {
        auto [du, u] = mq.top();
        mq.pop();
        if (du != d[u])
            continue;
        for (auto [dv, v] : adj[u])
            if (d[v] > dv + du)
            {
                d[v] = dv + du;
                c[v] = c[u];
                mq.push({d[v], v});
            }
        elif (dv + du == d[v]) c[v] += c[u];
    }
    cout << d[n] << ' ' << c[n];
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    adj.resize(n + 1);
    ll k, u, v, w;
    while (cin >> k >> u >> v >> w)
    {
        if (k == 1)
        {
            adj[u].pb({w, v});
        }
        else
        {
            adj[u].pb({w, v});
            adj[v].pb({w, u});
        }
    }
    dijkstra();
    return 0;
}