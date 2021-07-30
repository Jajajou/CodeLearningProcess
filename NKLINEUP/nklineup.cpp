/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "nklineup" //pls dont forget your task's name
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
struct Node
{
    int Min, Max;
    Node(int minn = 0, int maxx = 0) { Min = minn, Max = maxx; }
} tree[4 * maxn];
int n(0), q(0), a[maxn], leftt(0), rightt(0);

Node operator+(const Node &a, const Node &b)
{
    Node Res;
    Res.Max = max(a.Max, b.Max);
    Res.Min = min(a.Min, b.Min);
    return Res;
}

void createTree(int start, int end, int id)
{
    if (start == end)
    {
        tree[id] = {a[start], a[start]};
        return;
    }
    int mid = (start + end) >> 1;
    createTree(start, mid, 2 * id);
    createTree(mid + 1, end, 2 * id + 1);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void get(int start, int end, int qL, int qR, int id)
{
    if (qL > end || start > qR)
        return;
    if (qL <= start && end <= qR)
    {
        leftt = min(leftt, tree[id].Min);
        rightt = max(rightt, tree[id].Max);
        return;
    }
    int mid = (start + end) >> 1;
    get(start, mid, qL, qR, id * 2);
    get(mid + 1, end, qL, qR, id * 2 + 1);
}

void read()
{
    cin >> n >> q;
    forup(int, i, 1, n) cin >> a[i];
    createTree(1, n, 1);
}

void solve()
{
    int l(0), r(0);
    while (cin >> l >> r)
    {
        rightt = INT_MIN;
        leftt = INT_MAX;
        get(1, n, l, r, 1);
        cout << rightt - leftt << endl;
    }
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