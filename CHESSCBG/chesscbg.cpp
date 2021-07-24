/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "chesscbg" //pls dont forget your task's name
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
val getBit(val x, val pos) { return x >> pos & 1; }
template <class val>
val setBitVal(val pos, val x, val &inp) { return (x == 1) ? inp |= (1 << pos) : inp &= ~(1 << pos); }

typedef long long ll;
typedef unsigned long long ull;

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
string in1[4], in2[4];

void read()
{
    for (int i = 0; i < 4; ++i)
        cin >> in1[i];
    for (int i = 0; i < 4; ++i)
        cin >> in2[i];
}

bool inRange(int x, int y) { return x >= 0 && x <= 3 && y >= 0 && y <= 3; }

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void solve()
{
    int cp(0), dp[1 << 16], f[1 << 16];
    forup(int, i, 0, 3) forup(int, j, 0, 3) if (in1[i][j] - '0')
        cp += (1 << (i * 4 + j));
    dp[cp] = 0;
    f[cp] = 1;
    deque<int> q;
    q.pb(cp);
    while (!q.empty())
    {
        int state(q.front());
        q.pop_front();
        forup(int, pos, 0, 15)
        {
            if (!getBit(state, pos))
                continue;
            int i(pos / 4), j(pos % 4);
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k], y = j + dy[k];
                if (inRange(x, y))
                {
                    if (getBit(state, (x * 4 + y)))
                        continue;
                    int cpState = state - (1 << (i * 4 + j)) + (1 << (x * 4 + y));
                    if (f[cpState])
                        continue;
                    f[cpState] = 1;
                    dp[cpState] = dp[state] + 1;
                    q.pb(cpState);
                }
            }
        }
    }
    int res(0);
    forup(int, i, 0, 3) forup(int, j, 0, 3) if (in2[i][j] - '0')
        res += (1 << (i * 4 + j));
    cout << dp[res];
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    read();
    solve();
    return 0;
}