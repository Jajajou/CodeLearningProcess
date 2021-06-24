/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "gs" //pls dont forget your task's name
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

void mainScript()
{
    char c(' ');
    int n(0);
    ll res(0);
    cin >> n;

    vector<int> a(n + 1, 0);
    map<ll, ll> f;
    f[0] = 1;
    forup(i, 1, n)
    {
        cin >> c;
        a[i] = a[i - 1] + (c - '0');
        ++f[a[i] - i];
    }
    for (pair<ll, ll> x : f)
    {
        res += x.second * (x.second - 1) / 2;
    }
    cout << res << endl;
}

int main()
{
    boost();
    // IO();
    int t(0);
    cin >> t;
    while (t--)
    {
        mainScript();
    }
    return 0;
}