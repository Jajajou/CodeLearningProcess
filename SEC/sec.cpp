/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "sec" //pls dont forget your task's name
#define maxn int(5e5) + 55
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
int m(0), n(0), cnt(0);
int trie[maxn][2], leaf[maxn], node[maxn];

void add(int p[], int n)
{
    int u(0);
    forup(int, i, 0, n)
    {
        if (trie[u][p[i]] == 0)
            trie[u][p[i]] = ++cnt;
        u = trie[u][p[i]];
        ++node[u];
    }
    ++leaf[u];
}

int find(int p[], int n)
{
    int u(0), res(0);
    bool ok(1);
    forup(int, i, 0, n)
    {
        if (trie[u][p[i]] == 0)
        {
            ok = 0;
            break;
        }
        else
        {
            u = trie[u][p[i]];
            res += leaf[u];
        }
    }
    if (ok)
        res += node[u] - leaf[u];
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> m >> n;
    for (int i(0), l; i < m && cin >> l; ++i)
    {
        int p[l];
        forup(int, j, 0, l - 1) cin >> p[j];
        add(p, l - 1);
    }
    for (int i(0), l; i < n && cin >> l; ++i)
    {
        int p[l];
        forup(int, j, 0, l - 1) cin >> p[j];
        cout << find(p, l - 1) << endl;
    }
    return 0;
}