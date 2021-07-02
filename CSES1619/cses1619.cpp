/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "cses1619" //pls dont forget your task's name
#define f first
#define s second
#define maxn 101001
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)

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
    int n(0), res(0);
    cin >> n;

    vector<pair<int, int>> v(2 * n);
    int l(0), r(0);
    for (int i = 0; i < n && cin >> l >> r; ++i)
    {
        v.push_back({l, 1});
        v.push_back({r, -1});
    }
    sort(v.begin(), v.end());
    map<int, ll> prl;
    prl[0] = v[0].f;
    cout << prl[0] << " ";
    return 0;
}