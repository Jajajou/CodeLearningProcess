/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "symprime" //pls dont forget your task's name
#define maxn 101001
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
typedef long long ll;
using namespace std;
int pSize(0), prime[int(2e7) + 1] = {}, notPrime[int(2e7) + 1] = {};

void sieve()
{
    int n(int(2e7));
    notPrime[1] = -1;
    forup(i, 2, int(sqrt(n)))
    {
        if (!notPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                notPrime[j] = -1;
        }
    }
    forup(i, 1, n)
    {
        if (!notPrime[i])
        {
            prime[++pSize] = i;
            notPrime[i] = pSize;
        }
    }
}

void solve(int x)
{
    int k = notPrime[x];
    if (k > 0 && (prime[k - 1] + prime[k + 1]) / 2 == x)
        printf("YES\n");
    else
        printf("NO\n");
}

void read()
{
    int number;
    scanf("%d\n", &number);
    solve(number);
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    sieve();
    int t(0);
    scanf("%d\n", &t);
    while (t--)
    {
        read();
    }
}