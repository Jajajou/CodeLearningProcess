/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "vd2" //pls dont forget your task's name
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
int n(0), k(0), a[maxn] = {};

void read()
{
    cin >> n >> k;
}

void solve(int x)
{
    if (x > k)
        return;
    forup(i, a[x - 1] + 1, n)
    {
        a[x] = i;
        if (x == k)
        {
            forup(j, 1, k) cout << a[j] << ' ';
            cut;
        }
        solve(x + 1);
    }
}

int main()
{
    boost();
    IO();
    read();
    solve(1);
}