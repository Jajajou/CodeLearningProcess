/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "dutiec" // pls dont forget your task's name
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
int n(0);
string key[22];
vector<int> G[22];

bool link(string a, string b)
{
    vector<bool> ex(26, 0);
    forup(int, i, 0, (int)a.size() - 1) ex[a[i] - 'A'] = 1;
    forup(int, i, 0, (int)b.size() - 1) if (ex[b[i] - 'A']) return 1;
    return 0;
}

bool visited[22], found(0);
int pos[22], num(0);
void dfs(int u)
{
    visited[u] = 1;
    pos[++num] = u;
    for (int v : G[u])
    {
        if (found)
            return;
        if (v == 1 && num == n)
        {
            found = 1;
            forup(int, i, 1, num) cout << pos[i] << endl;
            return;
        }
        elif (!visited[v] && num < n)
        {
            dfs(v);
            --num, visited[v] = 0;
        }
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 1, n) cin >> key[i];
    forup(int, u, 1, n) forup(int, v, u + 1, n) if (link(key[u], key[v])) G[u].pb(v), G[v].pb(u);
    dfs(1);
    if (!found)
        return cout << "NO SOLUTION", 0;
}