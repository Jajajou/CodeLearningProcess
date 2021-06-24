/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "ipara" //pls dont forget your task's name
#define maxn 101
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
int n(0), cp(0), res(1), f[maxn] = {};

void read()
{
    cin >> n;
}

void solve(int x)
{
    if (x == n)
    {
        cout << n << endl;
        return;
    }
    forup(i, 0, (n - cp) / x)
    {
        f[x] = i;
        cp += f[x] * x;
        if (cp == n)
        {
            ++res;
            forup(j, 1, 31)
            {
                if (f[j]--)
                    cout << j << " ";
            }
            cout << endl;
        }
        else if (cp < n)
            solve(x + 1);
        cp -= f[x] * x;
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(1);
    cout << res;
}