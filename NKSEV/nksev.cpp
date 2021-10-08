/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "nksev" //pls dont forget your task's name
#define maxn int(3e5) + 35
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
const int MOD = 1337377;
int trie[maxn][26], dp[maxn], n, cnt, leaf[maxn];
string s;

void add(string p, int n)
{
    int u(0);
    fordown(int, i, n, 1)
    {
        if (trie[u][p[i] - 'a'] == 0)
            trie[u][p[i] - 'a'] = ++cnt;
        u = trie[u][p[i] - 'a'];
    }
    ++leaf[u];
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> s >> n;
    s = ' ' + s;
    forup(int, i, 1, n)
    {
        string g;
        cin >> g;
        g = ' ' + g;
        add(g, g.size() - 1);
    }
    dp[0] = 1;
    forup(int, i, 1, s.size() - 1)
    {
        int u(0);
        for (int j(i); j && trie[u][s[j] - 'a']; --j)
        {
            if (leaf[u = trie[u][s[j] - 'a']])
            {
                (dp[i] += dp[j - 1]) %= MOD;
            }
        }
    }
    cout << dp[s.size() - 1];
    return 0;
}