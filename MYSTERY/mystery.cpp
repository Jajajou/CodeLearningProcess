/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "mystery" //pls dont forget your task's name
#define maxn 20122007
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
unsigned int a(1);

void read()
{
    cin >> a;
}

long long exp(long long a, long long b)
{
    if (!b)
        return 1;
    long long cp(exp(a, b / 2));
    cp *= cp % maxn;
    if (b & 1)
        return ((cp % maxn) * a) % maxn;
    else
        return (cp % maxn);
}

void solve()
{
    long long res(1);
    forup(i, 1, sqrt(a))
    {
        if (a % i == 0)
        {
            res *= (exp(3, i) - 1);
            res %= maxn;
            if (i * i != a)
            {
                res *= (exp(3, a / i) - 1);
                res %= maxn;
            }
        }
    }
    cout << res;
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}