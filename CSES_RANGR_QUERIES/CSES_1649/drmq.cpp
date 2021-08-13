/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "drmq" //pls dont forget your task's name
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
template <class val>
class Seg
{
private:
    val cmp(val a, val b) { return min(a, b); }
    const val cp = 1e9;
    vector<val> tree;
    int n;

public:
    void init(int _n) { n = _n, tree.assign(4 * n, cp); }
    void update(int pos, val value)
    {
        tree[pos += n] = value;
        for (pos /= 2; pos; pos /= 2)
            tree[pos] = cmp(tree[2 * pos], tree[2 * pos + 1]);
    }
    val get(int l, int r)
    {
        val leftChild(cp), rightChild(cp);
        for (l += n, r += (n + 1); l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                leftChild = cmp(leftChild, tree[l++]);
            if (r & 1)
                rightChild = cmp(rightChild, tree[--r]);
        }
        return cmp(leftChild, rightChild);
    }
};
Seg<int> st;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0), k(0);
    cin >> n >> k;
    st.init(n + 1);
    for (int i(1), x(0); i <= n && cin >> x; ++i)
        st.update(i, x);
    int id, a, b;
    while (cin >> id >> a >> b)
    {
        if (2 - id)
            st.update(a, b);
        else
            cout << st.get(a, b) << '\n';
    }
    return 0;
}
