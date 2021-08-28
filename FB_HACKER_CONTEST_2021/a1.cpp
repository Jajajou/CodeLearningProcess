/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "a1" //pls dont forget your task's name
#define maxn 101001
#define elif else if
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

template <class val>
val getBit(val x, val pos)
{
    return x >> pos & 1;
}
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }
template <class val>
const void maximize(val &a, val b)
{
    a = max(a, b);
}
template <class val>
const void minimize(val &a, val b)
{
    a = min(a, b);
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
bool checkVowel[26];

void init()
{
    checkVowel['A' - 'A'] = 1;
    checkVowel['E' - 'A'] = 1;
    checkVowel['I' - 'A'] = 1;
    checkVowel['O' - 'A'] = 1;
    checkVowel['U' - 'A'] = 1;
}

int solve(string inp)
{
    int res(INT_MAX), n(0);
    forup(int, c, 0, inp.size() - 1) maximize(n, inp[c] - 'A');
    forup(int, i, 0, n)
    {
        int cp(0);
        forup(int, c, 0, inp.size() - 1)
        {
            int k(inp[c] - 'A');
            if (k == i)
                continue;
            if (checkVowel[k] == checkVowel[i])
                cp += 2;
            else
                cp++;
        }
        minimize(res, cp);
    }
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    init();
    int t(0);
    cin >> t;
    forup(int, i, 1, t)
    {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << solve(s);
        if (i < t)
            cout << '\n';
    }
    return 0;
}