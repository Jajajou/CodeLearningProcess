/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "syllable" //pls dont forget your task's name
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
string s;

bool ok(char x) { return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'; }

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int vowels(0), sLen(0);
    cin >> s;
    sLen = s.length();
    for (int i = 0; i < sLen; i++)
    {
        if (ok(s[i]))
        {
            ++vowels;
            if (ok(s[i + 1]))
            {
                --vowels;
            }
        }
    }
    cout << vowels << endl;
    if (s[sLen - 1] == 'e' !ok(s[sLen - 2]) || !ok(s[sLen - 3])))
        {
            --vowels;
            vowels += (vowels < 1);
        }
    cout << vowels;
    return 0;
}