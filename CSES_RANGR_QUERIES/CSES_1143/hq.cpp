/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "hq" //pls dont forget your task's name
#define maxn int(2e5)
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
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
int n(0), q(0);
ll seg[4 * maxn], h[maxn];
void buildTree(int start = 1, int end = n, int id = 1)
{
    if (start == end)
        return (void)(seg[id] = h[start]);
    int mid((start + end) / 2);
    buildTree(start, mid, id * 2);
    buildTree(mid + 1, end, id * 2 + 1);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

void update(ll val, int start = 1, int end = n, int id = 1)
{
    if (start == end)
        return (void)(seg[id] -= val, cout << start << ' ');
    int mid((start + end) / 2);
    if (seg[2 * id] >= val)
        update(val, start, mid, id * 2);
    else
        update(val, mid + 1, end, id * 2 + 1);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> q;
    forup(int, i, 1, n) cin >> h[i];
    buildTree();
    while (q--)
    {
        ll c;
        cin >> c;
        if (c > seg[1])
            cout << 0 << ' ';
        else
            update(c);
    }
    return 0;
}