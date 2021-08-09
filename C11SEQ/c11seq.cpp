/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "c11seq" //pls dont forget your task's name
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

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const void IO()
{
    Fin(name);
    Fout(name);
}
struct SumIndex : private vector<LL>
{
    SumIndex(const vector<int> &a)
    {
        set<LL> s;
        LL sum = 0;
        s.insert(sum);
        for (int x : a)
            sum += x, s.insert(sum);
        vector<LL>::operator=(vector<LL>(s.begin(), s.end()));
    }
    int operator()(LL x) const
    {
        return upper_bound(begin(), end(), x) - begin();
    }
    int size() const
    {
        return vector::size();
    }
};

struct Fenwick
{
    int n, *f;
    Fenwick(int n) : n(n), f(new int[n + 1]()) {}
    ~Fenwick() { delete[] f; }
    void up(int i)
    {
        for (; i <= n; i += i & -i)
            f[i]++;
    }
    int sum(int i)
    {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += f[i];
        return res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n;
    cin >> n;
    LL l, r;
    cin >> l >> r;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    SumIndex index(a);
    LL sum = 0, res = 0;
    Fenwick f(index.size());
    f.up(index(sum));
    for (int x : a)
    {
        sum += x;
        res += f.sum(index(sum - l)) - f.sum(index(sum - r - 1));
        f.up(index(sum));
    }
    cout << res;
    return 0;
}