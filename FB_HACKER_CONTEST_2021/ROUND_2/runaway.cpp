/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "runaway" //pls dont forget your task's name
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

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int t(0);
    cin >> t;
    forup(int, T, 1, t)
    {
        int n(0), m(0);
        cin >> n >> m;
        set<int> cnt;
        vector<int> s(m + 1, 0);
        vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
        forup(int, i, 1, m)
        {
            cin >> s[i];
            if (cnt.find(s[i]) == cnt.end() || cnt.empty())
                cnt.insert(s[i]);
        }
        bool zero(1);
        forup(int, i, 1, n) forup(int, j, 1, m)
        {
            cin >> p[i][j];
            if (cnt.find(p[i][j]) == cnt.end())
            {
                zero = 0;
                if (cnt.find(p[i][j]) == cnt.end())
                    cnt.insert(p[i][j]);
            }
        }
        if (zero)
        {
            cout << "Case #" << T << ": " << 0;
        }
        elif (m == 1)
        {
            cout << "Case #" << T << ": " << cnt.size() - 1;
        }
        else
        {
            cout << "Case #" << T << ": " << cnt.size() - 2 * m;
        }
        if (T < t)
            cout << '\n';
    }
    return 0;
}