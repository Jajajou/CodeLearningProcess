/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "bignum" //pls dont forget your task's name
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
typedef vector<int> bigInt;
const int BASE = 1000;
const int LENGTH = 3;

bigInt &fix(bigInt &a)
{
    a.push_back(0);
    for (int i = 0; i + 1 < a.size(); ++i)
    {
        a[i + 1] += a[i] / BASE;
        a[i] %= BASE;
        if (a[i] < 0)
            a[i] += BASE, --a[i + 1];
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

bigInt big(int x)
{
    bigInt res;
    while (x > 0)
    {
        res.push_back(x % BASE);
        x /= BASE;
    }
    return fix(res), res;
}

bigInt big(string s)
{
    bigInt res(s.size() / LENGTH + 1);
    for (int i = 0; i < s.size(); ++i)
    {
        int pos = (s.size() - i - 1) / LENGTH;
        res[pos] = res[pos] * 10 + s[i] - '0';
    }
    return fix(res), res;
}

//compare
int compare(bigInt &a, bigInt &b)
{
    if (a.size() != b.size())
        return (int)a.size() - (int)b.size();
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            return a[i] - b[i];
    return 0;
}
#define DEFINE_OPERATOR(x) \
    bool operator x(bigInt &a, bigInt &b) { return compare(a, b) x 0; }
DEFINE_OPERATOR(==)
DEFINE_OPERATOR(!=)
DEFINE_OPERATOR(>)
DEFINE_OPERATOR(<)
DEFINE_OPERATOR(>=)
DEFINE_OPERATOR(<=)
#undef DEFINE_OPERATOR

void operator+=(bigInt &a, bigInt b)
{
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i)
        a[i] += b[i];
    fix(a);
}

void operator-=(bigInt &a, bigInt b)
{
    for (int i = 0; i < b.size(); ++i)
        a[i] -= b[i];
    fix(a);
}

void operator*=(bigInt &a, int b)
{
    for (int i = 0; i < a.size(); ++i)
        a[i] *= b;
    fix(a);
}

void divide(bigInt a, int b, bigInt &q, int &r)
{
    for (int i = int(a.size()) - 1; i >= 0; --i)
    {
        r = r * BASE + a[i];
        q.push_back(r / b);
        r %= b;
    }
    reverse(q.begin(), q.end());
    fix(q);
}

bigInt operator+(bigInt a, bigInt b)
{
    a += b;
    return a;
}
bigInt operator-(bigInt a, bigInt b)
{
    a -= b;
    return a;
}
bigInt operator*(bigInt a, int b)
{
    a *= b;
    return a;
}

bigInt operator/(bigInt a, int b)
{
    bigInt q;
    int r = 0;
    divide(a, b, q, r);
    return q;
}
int operator%(bigInt a, int b)
{
    bigInt q;
    int r = 0;
    divide(a, b, q, r);
    return r;
}

bigInt operator*(bigInt a, bigInt b)
{
    bigInt result(a.size() + b.size());
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            result[i + j] += a[i] * b[j];
    return fix(result);
}

istream &operator>>(istream &cin, bigInt &a)
{
    string s;
    cin >> s;
    a = big(s);
    return cin;
}

ostream &operator<<(ostream &cout, const bigInt &a)
{
    cout << a.back();
    for (int i = (int)a.size() - 2; i >= 0; --i)
        cout << setw(LENGTH) << setfill('0') << a[i];
    return cout;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    bigInt a, b;
    cin >> a >> b;
    cout << a + b << '\n';
    if (a < b)
        cout << '-' << b - a << '\n';
    else
        cout << a - b << '\n';
    cout << a * b;
    return 0;
}