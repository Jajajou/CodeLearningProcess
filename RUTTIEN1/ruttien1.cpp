/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ruttien1" //pls dont forget your task's name
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
short m(0), x[4] = {};
int res(0), cp(0);

void read()
{
    cin >> m;
    forup(i, 0, 3) cin >> x[i];
}

void solve(int i)
{
    if (i > 3)
        return;
    forup(j, 0, m - x[i] + 1)
    {
        cp += j * x[i];
        res += (cp == m);
        if (cp != m)
            solve(i + 1);
        cp -= j * x[i];
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(0);
    cout << res;
}