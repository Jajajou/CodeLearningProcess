/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "bai2" //pls dont forget your task's name
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
int n(0), x[maxn] = {};
bool check(0);

void read()
{
    cin >> n;
    if (n < 4)
    {
        cout << 0;
        exit(0);
    }
}

void show()
{
    int count(0);
    forup(i, 1, n - 1)
    {
        if (x[i] == 0 && x[i + 1] == 1)
            ++count;
    }
    if (count > 1)
    {
        forup(i, 1, n) cout << x[i];
        cut;
    }
}

void nextBit()
{
    int i(n);
    while (x[i] == 1 && i)
        --i;
    if (!i)
        check = 1;
    else
    {
        ++x[i];
        if (i < n)
            forup(j, i + 1, n) x[j] = 0;
    }
}

void solve()
{
    while (!check)
    {
        show();
        nextBit();
    }
}

int main()
{
    boost();
    IO();
    read();
    solve();
}