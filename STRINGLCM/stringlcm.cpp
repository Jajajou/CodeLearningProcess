/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "stringlcm" //pls dont forget your task's name
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

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

string stringLCM(string s, int n)
{
    string result = s;
    for (int i = 0; i < n - 1; i++)
    {
        result.append(s);
    }
    return result;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    string a(""), b("");
    cin >> a >> b;
    int resLen(lcm(a.length(), b.length()));
    string cp1 = stringLCM(a, resLen / a.length());
    string cp2 = stringLCM(b, resLen / b.length());
    cout << cp1 << " " << cp2 << endl;
    if (cp1 == cp2)
        cout << cp1;
    else
        cout << -1;
    return 0;
}