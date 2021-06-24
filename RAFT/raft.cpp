/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "raft" //pls dont forget your task's name
#define maxn 101001
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;

unsigned int solve(unsigned int n, unsigned short k)
{
    if ((n - k) & 1 || n < k + 2)
        return 1;
    return solve((n - k) / 2, k) + solve((n + k) / 2, k);
}

void read()
{
    unsigned int n(1);
    unsigned short k(1);
    cin >> n >> k;
    cout << solve(n, k);
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
}