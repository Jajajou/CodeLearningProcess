/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "hieulp" //pls dont forget your task's name
#define maxn 11
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
typedef long long ll;
using namespace std;

bool checkPrime(ll x) {
    forup(i,2,int(sqrt(x))) {
        if(x%i==0)
            return 0;
    }
    return x > 1;
}

ll sumV(ll a, ll b) {
    return (a*a)+(a*b)+(b*b);
}

void readnSolve()
{
    ll a;
    scanf("%lld\n", &a);
    ll s(sumV(a-1,a));
    if(checkPrime(s))
    cout << 1 << endl; else cout << 0 << endl;
}

int main()
{
    boost();
    int q(0);
    scanf("%d\n", &q);
    while(q--) {
        readnSolve();
    }
}
