/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "power" //pls dont forget your task's name
#define maxn 1000000009
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;

long long exp(long long a, long long b)
{
    if (!b)
        return 1;
    long long s(exp(a, b / 2));
    s *= s % maxn;
    if (b & 1)
        return ((s % maxn) * a) % maxn;
    else
        return (s % maxn);
}

void read()
{
    short t(0);
    long long a(0), b(0);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        a %= maxn;
        cout << exp(a, b) << endl;
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
}