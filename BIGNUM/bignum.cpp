/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "bignum" //pls dont forget your task's name
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
typedef string bignum;
bignum a, b;

int cmp(bignum x, bignum y)
{
    while (x.size() < y.size())
        x = "0" + x;
    while (x.size() > y.size())
        y = "0" + y;
    if (x == y)
        return 0;
    if (x > y)
        return 1;
    return -1;
}

bignum sum(bignum x, bignum y)
{
    bignum res("");
    int carry(0), tmp(0);
    while (x.size() < y.size())
        x = "0" + x;
    while (x.size() > y.size())
        y = "0" + y;
    fordown(i, x.size() - 1, 0)
    {
        tmp = (x[i] - '0') + (y[i] - '0') + carry;
        carry = tmp / 10;
        res = to_string(tmp % 10) + res;
    }
    if (carry)
        res = '1' + res;
    return res;
}

bignum minor(bignum x, bignum y)
{
    bignum res("");
    bool ok(1);
    while (x.size() < y.size())
        x = "0" + x;
    while (x.size() > y.size())
        y = "0" + y;
    if (cmp(y, x))
    {
        bignum z = x;
        x = y;
        y = z;
        ok = 0;
    }
    int tmp(0), carry(0);
    fordown(i, x.size() - 1, 0)
    {
        tmp = (x[i] - '0') - (y[i] - '0') - carry;
        if (tmp < 0)
        {
            tmp += 10;
            carry = 1;
        }
        else
            carry = 0;
        res = to_string(tmp) + res;
    }
    while (res.size() and res[0] == '0')
        res.erase(0, 1);
    if (!ok)
        res = '-' + res;
    return res;
}

void read()
{
    cin >> a >> b;
}

void solve()
{
    cout << sum(a, b) << endl;
    cout << minor(a, b);
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}