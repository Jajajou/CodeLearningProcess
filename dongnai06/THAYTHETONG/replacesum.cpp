/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "replacesum" //pls dont forget your task's name
#define maxn int(2e5) + 1
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
int n(0);
priority_queue<ll, vector<ll>, greater<ll>> f;

void read()
{
    ll cp(0), res(0);
    cin >> n;
    forup(i, 1, n)
    {
        cin >> cp;
        res += cp;
        f.push(cp);
    }
    cout << res << ' ';
}

void show(priority_queue<ll, vector<ll>, greater<ll>> a)
{
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;
}

void solve()
{
    ll cp1(0), cp2(0), res(0);
    while (f.size() != 1)
    {
        cp1 = f.top(), f.pop();
        cp2 = f.top(), f.pop();
        res += (cp1 + cp2);
        f.push(cp1 + cp2);
    }
    cout << res;
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}