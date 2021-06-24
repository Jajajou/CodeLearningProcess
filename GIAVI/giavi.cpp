/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "giavi" //pls dont forget your task's name
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
struct data
{
    int S, B;
};
data spice[11];
int n(0), tracker[11] = {}, res(INT_MAX);

void read()
{
    cin >> n;
    if (n == 1)
    {
        int a(0), b(0);
        cin >> a >> b;
        cout << abs(a - b);
        exit(0);
    }
    forup(i, 1, n) cin >> spice[i].S >> spice[i].B;
}

void solve(int i)
{
    forup(x, 0, 1)
    {
        tracker[i] = x;
        if (i == n)
        {
            int tempSum(0), tempProduct(1);
            forup(cp, 1, n)
            {
                if (tracker[cp])
                {
                    tempSum += spice[cp].B,
                        tempProduct *= spice[cp].S;
                }
                if (tempSum && tempProduct != 1)
                    res = min(res, abs(tempSum - tempProduct));
            }
        }
        else
            solve(i + 1);
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve(1);
    cout << res;
}