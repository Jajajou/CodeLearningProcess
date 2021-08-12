/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "srmq" //pls dont forget your task's name
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
const void maximize(int &a, int b) { a = max(a, b); }
const void minimize(int &a, int b) { a = min(a, b); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef const void (*funcc)(int &, int);

const void IO()
{
    Fin(name);
    Fout(name);
}
struct BIT
{
    int n, cp;
    vector<int> tree, arr;
    funcc optimal;
    BIT(int n, int cp, funcc func) : n(n), cp(cp), optimal(func), tree(n + 1, cp), arr(n + 1) {}
    void update(int val, int pos)
    {
        arr[pos] = val;
        for (; pos <= n; pos += pos & (-pos))
            optimal(tree[pos], val);
    }
    int get(int l, int r)
    {
        int res(cp);
        while (l <= r)
        {
            if (r - (r & -r) >= l)
                optimal(res, tree[r]), r -= r & -r;
            else
                optimal(res, arr[r]), r -= 1;
        }
        return res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), k(0);
    cin >> n >> k;
    BIT minBIT(n, INT_MAX, minimize);
    for (int i(1), x(0); i <= n && cin >> x; ++i)
        minBIT.update(x, i);
    int qL(0), qR(0);
    while (cin >> qL >> qR)
    {
        cout << minBIT.get(qL, qR) << endl;
    }
    return 0;
}