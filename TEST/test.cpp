/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "test" // pls dont forget your task's name
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
const int N = (1 << 22) + 5;
const int S = 2 * N;
int n;
int m;
bool hv[N];
bool used[S];
int ans;
int q[S];
int topQ;

void solve(int x)
{
    topQ = 0;
    q[topQ++] = x;
    used[x] = 1;
    for (int it = 0; it < topQ; it++)
    {
        x = q[it];
        if (x < (1 << n))
        {
            if (!used[x + (1 << n)])
            {
                cout << "x + (1 << n): " << x + (1 << n) << ' ' << x << '\n';
                used[x + (1 << n)] = 1;
                q[topQ++] = x + (1 << n);
            }
        }
        else
        {
            int y = (1 << (n + 1)) - 1 - x;
            if (!used[y] && hv[y])
            {
                cout << "(1 << (n + 1)) - 1 - x: " << y << ' ' << x << '\n';
                used[y] = 1;
                q[topQ++] = y;
            }
            for (int i = 0; i < n; i++)
            {
                y = x | (1 << i);
                if (!used[y])
                {
                    cout << "x | (1 << i): " << (x | (1 << i)) << ' ' << x << '\n';
                    used[y] = 1;
                    q[topQ++] = y;
                }
            }
        }
    }
}
string s = "0[){})";
bool check(int i, int j) { return (int(s[j] - s[i]) == 2) || (int(s[j] - s[i]) == 1); }

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int mask((1 << 6) - 1);
    forup(int, i, 0, 6) if (getBit(mask, i))
    {
        cout << (mask ^ (1 << i)) << endl;
    }
    return 0;
}