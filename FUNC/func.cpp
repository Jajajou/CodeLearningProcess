/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "func" //pls dont forget your task's name
#define maxn int(1e6) + 16
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
    Fin(name);
    Fout(name);
}
int k, r, p[maxn], q[maxn], M;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    function<void(int &, int &)> fixed = [&fixed](int &a, int &b)
    {
        int tmp(__gcd(a, b));
        a /= tmp, b /= tmp;
    };

    while (cin >> k >> r >> p[1] >> q[1] >> M)
    {
        fixed(p[1], q[1]);
        forup(int, i, 2, k)
        {
            p[i] = q[i - 1] * r + p[i - 1];
            q[i] = q[i - 1] * r;
            fixed(p[i], q[i]);
            swap(p[i], q[i]);
        }
        cout << p[k] % M << " " << q[k] % M << endl;
    }
    return 0;
}