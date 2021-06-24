/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "lambai" //pls dont forget your task's name
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
using namespace std;
int n(0), q(0);
ll x(0), cp(0), res(0);
map<ll, ll> f;

void read()
{
    f[0] = 0;
    cin >> n >> x >> q;
    forup(i, 1, n)
    {
        cin >> cp;
        f[i] = f[i - 1] + cp;
    }
}

int check(int u, int v)
{
    return f[v] - f[u - 1] < x;
}

void solve()
{
    int u(0), v(0);
    forup(i, 1, q)
    {
        cin >> u >> v;
        res += check(u, v);
    }
    cout << res;
}

int main()
{
    boost();
    read();
    solve();
}