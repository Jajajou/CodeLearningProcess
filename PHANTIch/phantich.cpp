/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "phantich" //pls dont forget your task's name
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
short n(0), k(0), a[201] = {}, cp(0);

void read()
{
    cin >> n >> k;
}

void show()
{
    fordown(i, 200, 1)
    {
        if (a[i])
            cout << i << " " << a[i] << endl;
    }
}

void solve(int i)
{
    if (i > k)
        return;
    if (k % i == 0)
        forup(j, 0, (n - cp) / i)
        {
            a[i] = j;
            cp += i * a[i];
            if (cp == n)
            {
                show();
                exit(0);
            }
            solve(i + 1);
            cp -= i * a[i];
        }
    else
        solve(i + 1);
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(2);
    cout << 0;
}