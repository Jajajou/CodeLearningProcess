/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "kquery" //pls dont forget your task's name
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
    Fin(name);
    Fout(name);
}
struct Query
{
    int l, r, k, id;

    bool operator<(const Query &q) { return k < q.k; }
} qs[int(2e5) + 25];
ii a[int(3e4) + 34];
int n(0), q(0), bit[int(3e4) + 34];

void read()
{
    cin >> n;
    forup(int, i, 1, n) a[i].se = i, cin >> a[i].fi;
    cin >> q;
    forup(int, i, 1, q) qs[i].id = i, cin >> qs[i].l >> qs[i].r >> qs[i].k;
    sort(a + 1, a + n + 1);
    sort(qs + 1, qs + 1 + q);
}

void update(int x)
{
    for (x; x <= n; x += x & (-x))
        ++bit[x];
}

int get(int x)
{
    int res(0);
    for (x; x; x -= x & (-x))
        res += bit[x];
    return res;
}

void solve()
{
    int res[q + 1];
    int i(n);
    fordown(int, x, q, 1)
    {
        while (a[i].fi > qs[x].k)
            update(a[i--].se);
        res[qs[x].id] = get(qs[x].r) - get(qs[x].l - 1);
    }
    forup(int, x, 1, q) cout << res[x] << "\n";
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