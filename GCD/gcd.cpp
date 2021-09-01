/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
#include <bits/stdc++.h>
#define name "gcd" //pls dont forget your task's name
#define maxn 101001
#define cut cout << endl
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

int main()
{
    boost();
    IO();
    ll n(0), res(0);
    cin >> n;

    vector<ll> a(n + 1), l(n + 1, 0), r(n + 2, 0);
    forup(i, 1, n) cin >> a[i];
    forup(i, 1, n)
    {
        l[i] = gcd(l[i - 1], a[i]);
        r[n - i + 1] = gcd(r[n - i + 2], a[n - i + 1]);
    }
    forup(i, 1, n) res = max(res, gcd(l[i - 1], r[i + 1]));
    cout << res;
    return 0;
}
*/
/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "gcd" //pls dont forget your task's name
#define maxn 5 * int(1e6) + 56
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
vector<int> a;
map<long long, int> cnt;
int spf[maxn];

void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < maxn; i++)
        spf[i] = i;

    for (int i = 4; i < maxn; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < maxn; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < maxn; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    sieve();
    cin >> n;
    a.resize(n);
    int firstGCD(1);
    for (int &v : a)
        cin >> v, firstGCD = __gcd(firstGCD, v);
    int cp(0), res(0);
    for (int v : a)
        v /= firstGCD;
    unordered_map<int, int> mpp;
    for (int v : a)
    {
        vector<int> p = getFactorization(v);
        set<int> s;
        for (int j : p)
            s.insert(j);
        for (auto it = s.begin(); it != s.end(); ++it)
            ++mpp[*it];
    }
    int mini = INT_MAX;
    for (auto it = mpp.begin(); it != mpp.end(); ++it)
        if ((n - it->se) < mini)
        {
            mini = n - it->se;
        }
    if (mini != INT_MAX)
        return cout << mini, 0;
    else
        return cout << -1, 0;
}