/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "tsp" //pls dont forget your task's name
#define maxn 22
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
int n(0), track[maxn][maxn] = {}, resVal(INT_MAX);
vector<int> path(maxn), res(maxn);
int tmpSum(0);
bool visited[maxn] = {false};

void read()
{
    cin >> n;
    forup(i, 1, n) forup(j, 1, n) cin >> track[i][j];
}

void update()
{
    if (resVal > tmpSum + track[path[n]][path[1]])
    {
        resVal = min(resVal, tmpSum + track[path[n]][path[1]]);
        res = path;
    }
}

void solve(int i)
{
    if (tmpSum >= resVal)
        return;
    forup(j, 1, n)
    {
        if (!visited[j])
        {
            path[i] = j;
            visited[j] = 1;
            tmpSum += track[path[i - 1]][j];
            if (i == n)
                update();
            else
                solve(i + 1);
            tmpSum -= track[path[i - 1]][j];
            visited[j] = 0;
        }
    }
}

int main()
{
    boost();
    IO();
    read();
    solve(1);
    forup(i, 1, n) cout << res[i] << " ";
    cout << res[1];
    return 0;
}