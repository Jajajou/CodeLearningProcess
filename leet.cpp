/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#include <vector>
#define name "leet" //pls dont forget your task's name
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
int n(3), m(3), k(0);
vector<vector<int>> f;

void read()
{
    int x(0);
    for (int i = 0; i < n; ++i)
    {
        vector<int> cur;
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            cur.push_back(x);
        }
        f.push_back(cur);
    }
    cin >> k;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>> &f, int k)
{
    int n(f.size()), m(f[0].size());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (i)
                f[i][j] += f[i - 1][j];
            if (j)
                f[i][j] += f[i][j - 1];
            if (i && j)
                f[i][j] -= f[i - 1][j - 1];
        }

    vector<vector<int>> answer;
    for (int i = 0; i < n; ++i)
    {
        vector<int> cp;
        for (int j = 0; j < m; ++j)
        {
            int x1(max(0, i - k)), x2(min(n - 1, i + k)), y1(max(0, j - k)), y2(min(m - 1, j + k));
            int sum(f[x2][y2]);
            if (x1)
                sum -= f[x1 - 1][y2];
            if (y1)
                sum -= f[x2][y1 - 1];
            if (x1 && y1)
                sum += f[x1 - 1][y1 - 1];
            cp.push_back(sum);
        }
        answer.push_back(cp);
    }
    return answer;
}

void solve()
{
    vector<vector<int>> res;
    res = matrixBlockSum(f, k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << res[i][j] << ' ';
        }
        cut;
    }
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}