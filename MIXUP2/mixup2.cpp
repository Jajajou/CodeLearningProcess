/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "mixup2" //pls dont forget your task's name
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
ll f[70000][17], tong = 0;

int TTD(int x)
{
    return x > 0 ? x : -x;
}

int main()
{
    Fin(name);
    Fout(name);
    int n, M, a[17], b[17], chay = 1;
    tong = 0;
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        f[0][i] = 1;
    b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] * 2;
        chay = chay + b[i];
    }
    for (int i = 1; i <= chay; i++)
    {
        int t[n], m = i;
        for (int j = 0; j < n; j++)
        {
            t[j] = m % 2;
            m = m / 2;
        }
        for (int j = 0; j < n; j++)
        {
            f[i][j] = 0;
            if (b[j] == i)
                f[i][j] = 1;
            else if (t[j] != 0)
            {
                for (int k = 0; k < n; k++)
                    if (TTD(a[j] - a[k]) > M)
                        f[i][j] += f[i - b[j]][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
        tong += f[chay][i];
    printf("%lld", tong);
}