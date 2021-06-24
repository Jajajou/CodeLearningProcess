/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "cheat" //pls dont forget your task's name
#define maxn 101001
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

int main()
{
    boost();
    Fin(name);
    Fout(name);
    int n(0), x(0), j(1);
    stack<int> f;
    f.push(j);
    cin >> n;
    forupIn(i, 1, n, x)
    {
        while (x > j)
        {
            ++j, f.push(j);
        }
        if (x == f.top())
            f.pop();
        else if (x < f.top())
        {
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
}