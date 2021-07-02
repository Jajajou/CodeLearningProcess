/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "cses1619" //pls dont forget your task's name
#define maxn 101001
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
    int n(0), l(0), r(0);
    cin >> n;

    vector<pair<int, int>> v;
    forup(int, i, 1, n)
    {
        cin >> l >> r;
        v.push_back({l, 1});
        v.push_back({r, -1});
    }

    sort(allVi(v));

    int tmp(0), res(0);
    for (pair<int, int> x : v)
    {
        tmp += x.second;
        res = max(res, tmp);
    }
    cout << res;
    return 0;
}