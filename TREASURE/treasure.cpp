/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "treasure" //pls dont forget your task's name
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
int res(0), matrix[5][5] = {}, n(3), h[4] = {-1, 0, 1, 0}, v[4] = {0, 1, 0, -1}, x[10] = {}, y[10] = {};
bool checkMatrix[5][5] = {};

void setcpValue()
{
    forup(i, 0, 4)
    {
        checkMatrix[0][i] = 1,
        checkMatrix[i][0] = 1,
        checkMatrix[4][i] = 1,
        checkMatrix[i][4] = 1;
    }
}

void read()
{
    forup(i, 1, n) forup(j, 1, n) cin >> matrix[i][j];
}

void solve(int i)
{
    forup(pos, 0, n)
    {
        int Horizontal(x[i - 1] + h[pos]),
            Vertical(y[i - 1] + v[pos]);
        if (!checkMatrix[Horizontal][Vertical])
        {
            x[i] = Horizontal, y[i] = Vertical;
            checkMatrix[x[i]][y[i]] = 1;
            if (i == 9)
            {
                int tempSum(0);
                forup(j, 1, 9)
                {
                    tempSum = tempSum * 10 + matrix[x[j]][y[j]];
                    res = max(tempSum, res);
                }
            }
            else
                solve(i + 1);
            checkMatrix[x[i]][y[i]] = 0;
        }
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    setcpValue();
    int t(0);
    cin >> t;
    while (t--)
    {
        read();
        res = 0;
        forup(i, 1, n)
        {
            forup(j, 1, n)
            {
                x[1] = i, y[1] = j;
                checkMatrix[i][j] = 1;
                solve(2);
                checkMatrix[i][j] = 0;
            }
        }
        cout << res << endl;
    }
}