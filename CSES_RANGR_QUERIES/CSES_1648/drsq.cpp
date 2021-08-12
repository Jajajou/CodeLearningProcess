/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "drsq" //pls dont forget your task's name
#define maxn 200002
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
vector<ll> arr(maxn, 0), tree(maxn, 0);
int n, q;
void update(int pos, ll val)
{
    for (; pos <= n; pos += pos & (-pos))
        tree[pos] += val;
}
ll get(int pos)
{
    ll res(0);
    for (; pos; pos -= pos & (-pos))
        res += tree[pos];
    return res;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> q;
    for (int i(1); i <= n && cin >> arr[i]; ++i)
        update(i, arr[i]);
    while (q--)
    {
        int id;
        cin >> id;
        if (2 - id)
        {
            int k;
            ll val;
            cin >> k >> val;
            update(k, -arr[k]);
            arr[k] = val;
            update(k, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        }
    }
    return 0;
}