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
    int data[50][50];
    int n, m, k, levelDataSum[50][50][50], dp[50][50][50];

    void emptyAllMatrix()
    {
        forup(int, i, 0, 49) forup(int, j, 0, 49)
        {
            data[i][j] = 0;
            forup(int, k, i, 49) levelDataSum[i][j][k] = dp[i][j][k] = 0;
        }
    }

    void initData(string inp[])
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                data[i][j] = inp[i][j] - '0';
        }
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
        int curr[m][m][m];
        forup(int, lever, 0, n - 1)
        {
            forup(int, i, 0, m - 3) forup(int, j, i + 1, m - 2) forup(int, k, j + 1, m - 1)
            {
                curr[i][j][k] =
            }
        }
        return res;
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