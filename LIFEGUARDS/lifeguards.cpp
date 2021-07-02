/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "lifeguards" //pls dont forget your task's name
#define maxn int(1e9)
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, end) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n;
    cin >> n;

    vector<pair<int, int>> a;
    a.push_back({0, 0});
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});
    }
    a.push_back({maxn, maxn});
    sort(allVi(a));

    int tot = 0, mn = maxn, l_end = -1, l_far = -1, r_end = -1;
    for (int i = 1; i <= n; i++)
    {
        l_end = max(a[i].first, a[i - 1].second);
        l_far = max(l_far, l_end);
        r_end = min(a[i].second, a[i + 1].first);
        mn = min(mn, max(0, r_end - l_end));
        tot += max(0, a[i].second - l_far);
    }
    cout << tot - mn;
    return 0;
}