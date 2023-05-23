/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ruttien1" // pls dont forget your task's name
#define maxn 101001
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
int m(0), x[5] = {};
int a(0), cp1(0), b(INT_MAX), cp2(0);

void read()
{
    cin >> m;
    m /= 10000;
    x[0] = 2;
    x[1] = 5;
    x[2] = 10;
    x[3] = 20;
    x[4] = 50;
}

void solve(int i)
{
    if (i > 4)
        return;
    forup(j, 0, int(m / x[i]))
    {
        cp1 += (j * x[i]);
        cp2 += j;
        if (cp1 == m)
        {
            ++a;
            b = min(b, cp2);
        }
        if (cp1 != m)
            solve(i + 1);
        cp2 -= j;
        cp1 -= (j * x[i]);
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    a = cp1 = cp2 = 0;
    solve(0);
    cout << a << " " << b;
}