/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "maxcross" //pls dont forget your task's name
#define maxn 101001
#define cut cout << endl
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".in", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

int main()
{
    boost();
    IO();
    int n(0), k(0), b(0), x(0);
    cin >> n >> k >> b;

    vector<int> brokenLight(n + 1, 0);
    forup(i, 1, b)
    {
        cin >> x;
        brokenLight[x] = 1;
    }

    forup(i, 1, n)
    {
        if (brokenLight[i])
            brokenLight[i] += brokenLight[i - 1];
        else
            brokenLight[i] = brokenLight[i - 1];
    }

    int res(k);
    forup(i, k, n)
    {
        res = min(res, brokenLight[i] - brokenLight[i - k]);
    }
    cout << res;
    return 0;
}