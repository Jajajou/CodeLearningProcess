/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "nhiphan" //pls dont forget your task's name
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
short n(0), x[11];

void read()
{
    cin >> n;
}

void show()
{
    forup(i, 1, n) cout << x[i] << " ";
    cout << endl;
}

void solve(int i)
{
    forup(j, 0, 1)
    {
        x[i] = j;
        if (i == n)
            show();
        else
            solve(i + 1);
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(1);
}