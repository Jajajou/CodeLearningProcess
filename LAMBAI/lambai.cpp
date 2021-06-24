/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
void xuat()
{
    cout << 1;
}
int check(int x, int y)
{
    if ((y - x) % (x - 1) == 0)
        return 2;
    return 0;
}
int main()
{
    freopen("lambai.inp", "r", stdin);
    freopen("lambai.out", "w", stdout);
    int m, n;
    scanf("%d %d", &n, &m);

    int s = m + 1;
    for (int i = 1; i <= m - 1; i++)
        s += check(m - i, n - i);
    printf("%d", s);
}