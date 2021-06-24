/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "gacho" //pls dont forget your task's name
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
unsigned short m(1);
int res(0), cp(0);

void read()
{
    cin >> m;
}

void solve(int x)
{
    if (x > 4)
        return;
    forup(i, 0, m / x)
    {
        cp += i * x;
        res += (cp == m);
        if (cp != m)
            solve(x + 2);
        cp -= i * x;
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(2);
    cout << res;
}