/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "mtwalk" //pls dont forget your task's name
#define maxn 105
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
int n(0), G[maxn][maxn] = {}, maxHeight(INT_MIN), minHeight(INT_MAX);
bool visited[maxn][maxn];

void read()
{
    cin >> n;
    forup(i, 1, n) forup(j, 1, n)
    {
        cin >> G[i][j];
        maxHeight = max(maxHeight, G[i][j]);
        minHeight = min(minHeight, G[i][j]);
        visited[i][0] = visited[0][i] = visited[i][n + 1] = visited[n + 1][i] = 1;
    }
}

void resetVisitedMark()
{
    forup(i, 1, n) forup(j, 1, n) visited[i][j] = 0;
    visited[1][1] = 1;
}

void bothQueuePop(queue<int> &a, queue<int> &b)
{
    b.pop(), a.pop();
}

int vertical[4] = {-1, 0, 1, 0},
    horizontal[4] = {0, 1, 0, -1};
bool conditionalBfs(int minCheck, int diffCheck)
{
    resetVisitedMark();
    queue<int> qX, qY;
    qX.push(1);
    qY.push(1);
    while (!qY.empty())
    {
        int x(qX.front()), y(qY.front());
        bothQueuePop(qX, qY);
        forup(k, 0, 3)
        {
            int u(x + vertical[k]), v(y + horizontal[k]);
            if (!visited[u][v] && G[u][v] >= minCheck && G[u][v] - minCheck <= diffCheck)
            {
                if (u == v && v == n)
                    return 1;
                visited[u][v] = 1;
                qX.push(u), qY.push(v);
            }
        }
    }
    return 0;
}

int binarySearch(int cp, int l, int r)
{
    int res(r);
    while (l <= r)
    {
        int mid(l + (r - l) / 2);
        if (conditionalBfs(cp, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

void solve()
{
    int res(INT_MAX);
    forup(i, minHeight, G[1][1])
        res = min(res, binarySearch(i, 0, maxHeight - minHeight));
    cout << res;
}

int main()
{
    boost();
    IO();
    read();
    solve();
}