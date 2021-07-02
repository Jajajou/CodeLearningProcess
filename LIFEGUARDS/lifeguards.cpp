/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "lifeguards" //pls dont forget your task's name
#define maxn int(1e9)
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".in", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, end) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin
#define pb push_back

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
    int n(0);
    cin >> n;
    vector<pair<int, int>> a;
    a.pb({0, 0});
    a.pb({maxn, maxn});
    forup(int, i, 1, n)
    {
        int u(0), v(0);
        cin >> u >> v;
        a.pb({u, v});
    }
    sort(allVi(a));

    int l(-1), r(-1), highest_l(-1), minimalLost(maxn), totalTime(0);
    forup(int, i, 1, n)
    {
        l = max(a[i].first, a[i - 1].second);
        highest_l = max(highest_l, l);
        r = min(a[i].second, a[i + 1].first);
        minimalLost = min(minimalLost, max(0, r - l));
        totalTime += max(0, a[i].second - highest_l);
    }
    cout << totalTime - minimalLost;

    return 0;
}