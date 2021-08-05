/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "shch" //pls dont forget your task's name
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
const int BASE = 1e9;
typedef vector<int> big;

void fix(big &a)
{
    while (a.size() >= 2 && a.back() == 0)
        a.pop_back();
}

big to_big(int x)
{
    assert(x < BASE);
    return big(1, x);
}

bool operator>=(big a, big b)
{
    fix(a), fix(b);
    if (a.size() != b.size())
        return (a.size() > b.size());
    for (int i = (int)a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] > b[i];
    return true;
}

big operator+(big a, big b)
{
    fix(a), fix(b);
    big c;
    int g = 0;
    for (int i = 0; i <= max(a.size(), b.size()) - 1; i++)
    {
        if (i < a.size())
            g += a[i];
        if (i < b.size())
            g += b[i];
        c.pb(g % BASE);
        g /= BASE;
    }
    if (g)
        c.pb(g);
    return fix(c), c;
}

big operator-(big a, big b)
{
    fix(a), fix(b);
    big c;
    int g = 0;
    for (int i = 0; i < a.size(); i++)
    {
        g += a[i];
        if (i < b.size())
            g -= b[i];
        if (g >= 0)
            c.pb(g), g = 0;
        else
            c.pb(g + BASE), g = -1;
    }
    return fix(c), c;
}
big operator*(const big &a, const big &b)
{
    big res(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i)
    {
        int tmp(0);
        for (int j = 0; j < b.size(); ++j)
        {
            ll s = (ll)res[i + j] + tmp + (ll)a[i] * b[j];
            res[i + j] = s % BASE;
            tmp = s / BASE;
        }
        if (tmp)
            res[i + b.size()] += tmp;
    }
    return fix(res), res;
}
big operator*(big a, int x)
{
    assert(x < BASE);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= x;
    return fix(a), a;
}
big operator/(big a, int x)
{
    assert(x < BASE);
    for (int i = (int)a.size() - 1, r = 0; i >= 0; --i, r %= x)
    {
        r = r * BASE + a[i];
        a[i] = r / x;
    }
    return fix(a), a;
}
int operator%(const big &a, int x)
{
    int r = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i)
        r = (r * BASE + a[i]) % x;
    return r;
}
istream &operator>>(istream &cin, big &a)
{
    string s;
    cin >> s;
    while (s.size() % 9)
        s = '0' + s;
    for (int i = 0; i < s.size(); i += 9)
    {
        ll b = 0;
        forup(int, j, i, i + 9 - 1) b = b * 10 + (s[j] - '0');
        a.insert(a.begin(), b);
    }
    return fix(a), cin;
}
ostream &operator<<(ostream &cout, const big &a)
{
    printf("%d", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        printf("%09d", a[i]);
    return cout;
}
int n, k, inArr[101];
big A[101], m;

void read()
{
    cin >> n >> k >> m;
    m = m - to_big(1);
    inArr[0] = 0;
    forup(int, i, 1, k) cin >> inArr[i];
    A[0] = to_big(1);
    forup(int, i, 1, n) A[i] = A[i - 1] * (n - k + i);
}

void solve1()
{
    bool taken[n + 1];
    forup(int, j, 0, n) taken[j] = 1;
    forup(int, i, 1, k)
    {
        int cnt(0), tmp(0);
        while (m >= A[k - i])
            m = m - A[k - i], ++cnt;
        forup(int, j, 1, n)
        {
            if (tmp == cnt && taken[j])
            {
                printf("%d%c", j, i == k ? '\n' : ' ');
                taken[j] = 0;
                break;
            }
            tmp += taken[j] != 0;
        }
    }
}

void solve2()
{
    big res(to_big(1));
    bool taken[n + 1];
    taken[0] = 0;
    forup(int, i, 1, n) taken[i] = 1;
    forup(int, i, 1, k)
    {
        int cnt(0);
        forup(int, j, 1, inArr[i] - 1) cnt += taken[j] != 0;
        res = res + A[k - i] * to_big(cnt);
        taken[inArr[i]] = 0;
    }
    cout << res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve1();
    solve2();
    return 0;
}