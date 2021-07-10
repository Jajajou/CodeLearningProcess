/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "starAdventure" //pls dont forget your task's name
#define maxn 101001
#define pri_q priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;

class beatTheGame
{
    int data[50][50], curr[50][50][50], n, m, k, levelDataSum[50][50][50], dp[50][50][50];

    void emptyAllMatrix()
    {
        forup(int, i, 0, 49) forup(int, j, 0, 49)
        {
            data[i][j] = 0;
            forup(int, k, 0, 49) levelDataSum[i][j][k] = dp[i][j][k] = 0;
        }
    }

    void resetCurr()
    {
        forup(int, i, 0, 49) forup(int, j, 0, 49) forup(int, k, 0, 49) curr[i][j][k] = 0;
    }

    void initData(string inp[])
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                data[i][j] = inp[i][j] - '0';
        }
    }

    void merge(int a[50][50][50], int b[50][50][50])
    {
        forup(int, i, 0, m - 1) forup(int, j, 0, m - 1) forup(int, k, 0, m - 1) a[i][j][k] = b[i][j][k];
    }

    void calDataSum()
    {
        forup(int, i, 0, n - 1) forup(int, j, 0, m - 1) forup(int, k, j, m - 1)
        {
            levelDataSum[i][j][k] = [&](int level, int start, int end)
            {
                int res(0);
                forup(int, i, start, end) res += data[level][i];
                return res;
            }(i, j, k);
        }
    }

    int calRes()
    {
        int res(0);
        calDataSum();
        if (m <= 3)
            return [&]()
            {
                int res(0);
                forup(int, i, 0, n - 1) res += levelDataSum[i][0][m - 1];
                return res;
            }();
        forup(int, level, 0, n - 1)
        {
            resetCurr();
            forup(int, i, 0, m - 3) forup(int, j, i + 1, m - 2) forup(int, k, j + 1, m - 1)
            {
                curr[i][j][k] = [&](int level, int endPos_1, int endPos_2, int endPos_3)
                {
                    int res(0);
                    forup(int, i, 0, endPos_1) forup(int, j, endPos_1 + 1, endPos_2) forup(int, k, endPos_2 + 1, endPos_3)
                        res = max(res, dp[i][j][k] + levelDataSum[level][i][endPos_1] + levelDataSum[level][j][endPos_2] + levelDataSum[level][j][endPos_3]);
                    return res;
                }(level, i, j, k);
            }
            merge(dp, curr);
        }
        return dp[m - 3][m - 2][m - 1];
    }

public:
    int solve(string inp[], int N, int M)
    {
        emptyAllMatrix();
        n = N, m = M;
        initData(inp);
        return calRes();
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    string s, base[50] = {};
    int i(0);
    while (cin >> s)
        base[i++] = s;
    cout << beatTheGame().solve(base, i, base[0].length());
    return 0;
}