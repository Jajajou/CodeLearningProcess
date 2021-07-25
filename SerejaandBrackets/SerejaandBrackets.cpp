/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "SerejaandBrackets" //pls dont forget your task's name
#define maxn int(1e6)
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

const void IO()
{
    Fin(name);
    Fout(name);
}
struct Node
{
    int optimized;
    int open;
    int close;

    Node(int opt = 0, int o = 0, int c = 0)
    {
        optimized = opt;
        open = o;
        close = c;
    }
};
int n(0);
string in("");
Node *tree = new Node[4 * maxn];

Node operator+(const Node &left, const Node &right)
{
    Node res;
    int tmp(min(left.open, right.close));
    res.optimized = left.optimized + right.optimized + tmp;
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;
    return res;
}

Node calQuery(int start, int end, int qL, int qR, int id)
{
    if (start > qR || end < qL)
        return {0, 0, 0};
    if (start >= qL && end <= qR)
        return tree[id];
    int mid = (start + end) / 2;
    return calQuery(start, mid, qL, qR, 2 * id) + calQuery(mid + 1, end, qL, qR, 2 * id + 1);
}

void createTree(int start, int end, int id)
{
    if (start > end)
        return;
    if (start == end)
    {
        tree[id] = Node(0, 0 + (in[start] == '('), 0 + (in[start] == ')'));
        return;
    }
    int mid = (start + end) / 2;
    createTree(start, mid, 2 * id);
    createTree(mid + 1, end, 2 * id + 1);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

int query(int l, int r)
{
    Node res = calQuery(1, n, l, r, 1);
    return res.optimized * 2;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> in;
    n = in.size();
    in = " " + in;
    createTree(1, n, 1);

    int q(0);
    cin >> q;
    while (q--)
    {
        int l(0), r(0);
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}