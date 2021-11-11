/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "tinnq01a" // pls dont forget your task's name
#define trinhChamUrl "D:\\C++\\TEST\\"
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
// #define Fin(name) freopen(trinhChamUrl name ".inp", "r", stdin)
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

int solve(string s)
{
    int l(0), r((int)s.size() - 1);
    while (int(s[l] - '0') % 3 == 0 || int(s[r] - '0') % 3 == 0 || (int(s[l] - '0') + int(s[r] - '0')) % 3 == 0)
    {
        while (int(s[l] - '0') % 3 == 0)
        {
            ++l;
            if (l > r)
                return r - l + 1;
        }
        while (int(s[r] - '0') % 3 == 0)
        {
            --r;
            if (l > r)
                return r - l + 1;
        }
        while ((int(s[l] - '0') + int(s[r] - '0')) % 3 == 0)
        {
            ++l, --r;
            if (l > r)
                return r - l + 1;
        }
    }
    return r - l + 1;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int T(0);
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}