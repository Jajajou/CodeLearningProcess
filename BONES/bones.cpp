/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "bones" //pls dont forget your task's name
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
int s1(0), s2(0), s3(0);

void read()
{
    cin >> s1 >> s2 >> s3;
}

void solve()
{
    int res(0), f[81] = {}, cp(0);
    fordown(x, s1, 1)
    {
        fordown(y, s2, 1)
        {
            fordown(z, s3, 1)
            {
                ++f[x + y + z];
                if (f[x + y + z] >= cp)
                {
                    res = x + y + z;
                    cp = f[x + y + z];
                }
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