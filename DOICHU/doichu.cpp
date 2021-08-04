/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "doichu" //pls dont forget your task's name
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
struct P
{
    int x, y;
    void read()
    {
        cin >> x >> y;
    }
    P operator-(const P &b) const
    {
        return {x - b.x, y - b.y};
    }
    void operator-=(const P &b)
    {
        x -= b.x;
        y -= b.y;
    }
    ll operator*(const P &b) const
    {
        return (ll)x * b.y - (ll)y * b.x;
    }
    ll triangle(const P &b, const P &c) const
    {
        return (b - *this) * (c - *this);
    }
    bool operator<(const P &b) const
    {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
    ll Dist(const P &b) const
    {
        return (ll)(x - b.x) * (x - b.x) + (ll)(y - b.y) * (y - b.y);
    }
};
const void IO()
{
    Fin(name);
    Fout(name);
}
string s;
int k(0);

void read()
{
    cin >> s >> k;
}

int solve(int n, int k, char ch)
{
    int maxlen(1), cnt(0), l(0), r(0);
    while (r < n)
    {
        if (s[r] != ch)
            ++cnt;
        while (cnt > k)
        {
            if (s[l] != ch)
                --cnt;
            ++l;
        }
        maxlen = max(maxlen, r - l + 1);
        ++r;
    }
    return maxlen;
}

void solve()
{
    int res(0);
    forup(int, i, 0, 26) res = max(res, solve(s.size(), k, 'a' + i));
    cout << res;
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