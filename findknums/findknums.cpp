/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "findknums" //pls dont forget your task's name
#define MAXN (ll)(1e5 + 1)
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
ll prime[MAXN], N;
map<ll, ll> cnt;

void sieve()
{
    prime[1] = 1;
    for (int i = 2; i < MAXN; i++)
        prime[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        prime[i] = 2;
    for (int i = 3; i * i < MAXN; i++)
    {
        if (prime[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)

                if (prime[j] == j)
                    prime[j] = i;
        }
    }
}

void tsnt(ll f)
{
    while (f > 1)
    {
        ll x = spf[f];
        while (f % x == 0)
        {
            cnt[x]++;
            f /= x;
        }
    }
}

ll gt(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll power(ll x, ll y)
{
    ll res = 1;
    x = x;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

void read()
{
    cin >> N;
}

void solve()
{
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    sieve();
    read();
    solve();
    return 0;
}