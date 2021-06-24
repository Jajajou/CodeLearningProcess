/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "stacking" //pls dont forget your task's name
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
    ll n(0);
    cin >> n;

    int q(0), u(0), v(0);
    vector<int> st(n + 1);
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        ++st[u], --st[v + 1];
    }
    forup(i, 1, n) st[i] += st[i - 1];
    sort(st.begin(), st.end());
    cout << st[n / 2 + 1];

    return 0;
}