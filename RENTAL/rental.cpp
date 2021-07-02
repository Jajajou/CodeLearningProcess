/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "rental" //pls dont forget your task's name
#define maxn 101001
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
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
    int n(0), m(0), r(0);
    cin >> n >> m >> r;

    vector<int> milksaCow, rentPrice;
    vector<pair<int, int>> milkTradePrice;
    for (int i(0), x(0); i < n && cin >> x; ++i)
        milksaCow.pb(x);
    for (int i(0), x(0), y(0); i < m && cin >> x >> y; ++i)
        milkTradePrice.pb({x, y});
    for (int i(0), x(0); i < n && cin >> x; ++i)
        rentPrice.pb(x);
    return 0;
}