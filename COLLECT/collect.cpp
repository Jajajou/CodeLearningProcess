/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "collect" //pls dont forget your task's name
#define maxn 101001
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, end) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
struct collection
{
    int z, s, m, k;
    collection() {}
    collection(int z, int s, int m, int k) : z(z), s(s), m(m), k(k) {}
    collection(int z, int s, int m) : z(z), s(s), m(m), k(0) {}
};
vector<pair<collection, collection>> trade;
int z(0), s(0), m(0), k(0), z0(0), s0(0), m0(0);
bool ok[5][5][5] = {{{0}}};

void read()
{
    cin >> k >> z >> s >> m >> z0 >> s0 >> m0;
    int z1(0), s1(0), m1(0), z2(0), s2(0), m2(0);
    while (cin >> z1 >> s1 >> m1 >> z2 >> s2 >> m2)
    {
        trade.pb({collection(z1, s1, m1), collection(z2, s2, m2)});
    }
}

bool check(int z, int s, int m) { return z <= 4 && s <= 4 && m <= 4 && !ok[z][s][m]; }

bool cmp(collection &a, collection &b)
{
    return a.z - b.z ? a.z < b.z : a.s - b.s ? a.s < b.s
                               : a.m - b.m   ? a.m < b.m
                               : a.k - b.k   ? a.k < b.k
                                             : 0;
}

void solve()
{
    queue<collection> q;
    vector<collection> res;
    q.push(collection(z, s, m)), ok[z][s][m] = 1;
    while (!q.empty())
    {
        collection cp = q.front();
        q.pop();
        if (cp.z >= z0 && cp.s >= s0 && cp.m >= m0)
            res.pb(cp);
        else
            for (pair<collection, collection> p : trade)
            {
                if (cp.z >= p.first.z && cp.s >= p.first.s && cp.m >= p.first.m && cp.k + 1 <= k)
                {
                    int z(cp.z - p.first.z + p.second.z),
                        s(cp.s - p.first.s + p.second.s),
                        m(cp.m - p.first.m + p.second.m);
                    if (check(z, s, m))
                        ok[z][s][m] = 1, q.push(collection(z, s, m, cp.k + 1));
                }
            }
    }
    if (!res.size())
        cout << -1;
    else
    {
        sort(allVi(res), cmp);
        cout << res.size() << endl;
        for (collection x : res)
            cout << x.z << ' ' << x.s << ' ' << x.m << ' ' << x.k << endl;
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    return 0;
}