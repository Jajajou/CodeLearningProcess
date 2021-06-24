/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "test" //pls dont forget your task's name
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
vector<int> a;

void read()
{
    int x(0), n(0);
    scanf("%d\n", &n);
    while (n--)
    {
        scanf("%d ", &x);
        a.push_back(x);
    }
}

int pivotIndex(vector<int> &nums)
{
    int sum(0), leftSum(0);
    for (int x : nums)
        sum += x;
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << ' ';
    for (int i = 0; i < nums.size(); ++i)
    {
        if (leftSum == sum - nums[i] - leftSum)
        {
            cout << sum << endl;
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

void solve()
{
    cout << pivotIndex(a);
}

int main()
{
    boost();
    IO();
    read();
    solve();
    return 0;
}