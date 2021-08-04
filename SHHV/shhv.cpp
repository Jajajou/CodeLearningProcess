/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "shhv" //pls dont forget your task's name
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
int f[13];

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int x(0), n(0), arr[13];
    f[0] = 1;
    while (cin >> x)
        arr[++n] = x;
    --n;
    forup(int, i, 1, n) f[i] = f[i - 1] * i;
    cout << 1 + [&]()
    {
        int res(0);
        bool taken[n + 1];
        forup(int, i, 1, n) taken[i] = 1;
        forup(int, i, 1, n)
        {
            int cnt(0);
            forup(int, j, 1, n) cnt += (j < arr[i] and taken[j]);
            res += f[n - i] * cnt;
            taken[arr[i]] = 0;
        }
        return res;
    }() << "\n";
    bool taken[n + 1];
    forup(int, i, 1, n) taken[i] = 1;
    forup(int, i, 1, n)
    {
        forup(int, j, 1, n) if (taken[j])
        {
            if (arr[n + 1] > f[n - i])
                arr[n + 1] -= f[n - i];
            else
            {
                cout << j << ' ';
                taken[j] = 0;
                break;
            }
        }
    }
    return 0;
}