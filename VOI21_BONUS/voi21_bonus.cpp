/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "voi21_bonus" // pls dont forget your task's name
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
#define Fin(name) freopen("D:\\C++\\VOI21_BONUS\\" name ".inp", "r", stdin)
// #define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
#define Fout(name) freopen("D:\\C++\\VOI21_BONUS\\" name ".out", "w", stdout)
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
ll p[int(3e5) + 53];
string c[int(3e5) + 53];
set<ii> luckyPair;

namespace sub1
{
    ll dp[101];

    bool checkStr(string s, string p)
    {
        forup(int, i, 0, (int)p.size() - 1) if (p[i] != s[i]) return 0;
        return 1;
    }

    void solve()
    {
        ll res(0);
        forup(int, i, 1, n) dp[i] = p[i];
        forup(int, i, 2, n)
        {
            forup(int, j, 1, i - 1)
            {
                if (checkStr(c[j], c[i]) || luckyPair.find({p[i], p[j]}) != luckyPair.end() || luckyPair.find({p[j], p[i]}) != luckyPair.end())
                    dp[i] = max(dp[i], dp[j] + p[i]);
            }
            maximize(res, dp[i]);
        }
        cout << res;
    }
}

namespace sub2
{
    ll dp[int(3e5) + 53];
    struct TrieNode
    {
        TrieNode *child[26];
        int leaf, val, id;
        TrieNode()
        {
            forup(int, i, 0, 25) child[i] = NULL;
            val = leaf = 0;
        }
    } * root;

    void add(string s, int id)
    {
        TrieNode *u = root;
        forup(int, i, 0, (int)s.size() - 1)
        {
            if (u->child[s[i] - 'A'] == NULL)
                u->child[s[i] - 'A'] = new TrieNode();
            u = u->child[s[i] - 'A'];
            if (u->val < p[id])
            {
                u->val = p[id];
                u->id = id;
            }
        }
        u->leaf++;
        if (u->val < p[id])
        {
            u->val = p[id];
            u->id = id;
        }
    }

    TrieNode *find(string s)
    {
        TrieNode *u = root;
        forup(int, i, 0, (int)s.size() - 1) if (u->child[s[i] - 'A'] == NULL) return NULL;
        else u = u->child[s[i] - 'A'];
        return u;
    }

    void solve()
    {
        root = new TrieNode();
        forup(int, i, 1, n) add(c[i], i), dp[i] = p[i];
        forup(int, i, 1, n)
        {
        }
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int maxLen(0);
    cin >> n >> m;
    forup(int, i, 1, n) cin >> c[i] >> p[i], maximize(maxLen, (int)c[i].size());
    ll u(0), v(0);
    while (cin >> u >> v)
        luckyPair.insert({u, v});
    if (n <= 100 && maxLen <= 100 && m > 0 && m <= 100)
        sub1::solve();
    else
        sub2::solve();
    return 0;
}