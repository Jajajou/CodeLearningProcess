/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "maxmedian" //pls dont forget your task's name
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

int main()
{
    boost();
    IO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int l = 1, r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
            if (a[i] >= m)
            {
                b[i] = 1;
            }
            else
            {
                b[i] = -1;
            }
        for (int i = 1; i < n; ++i)
            b[i] += b[i - 1];
        int mx = b[k - 1];
        int mn = 0;
        for (int i = k; i < n; ++i)
        {
            mn = min(mn, b[i - k]);
            mx = max(mx, b[i] - mn);
        }
        if (mx > 0)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << '\n';
    return 0;
}