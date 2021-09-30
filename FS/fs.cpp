/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "fs" //pls dont forget your task's name
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
int mid(-1);
ll area;
vector<ll> S;

int bs(int val, int l = 0, int r = S.size() - 1)
{
    if (r >= l)
    {
        int m((l + r) / 2);
        if (S[m] == val)
            return mid = S[m];
        elif (S[m] > val) return bs(val, l, m - 1);
        else return bs(val, m + 1, r);
    }
    return -1;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> area;
    for (int i(0); i * i <= int(1e9); ++i)
        S.pb(i * i);
    int x(-1), y(-1);
    for (int cp : S)
    {
        mid = -1;
        int cp2(bs(area - cp));
        if (cp2 != -1)
        {
            x = sqrt(cp), y = sqrt(cp2);
            return cout << 0 << ' ' << y << '\n'
                        << x << ' ' << 0 << '\n'
                        << x << ' ' << x + y << '\n'
                        << x + y << ' ' << y,
                   0;
        }
    }
    cout << "Impossible";
    return 0;
}