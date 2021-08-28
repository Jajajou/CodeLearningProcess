/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "military" //pls dont forget your task's name
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
struct P
{
    int x, y;
    P operator-(const P &b) const
    {
        return {x - b.x, y - b.y};
    }
    void operator-=(const P &b)
    {
        x -= b.x;
        y -= b.y;
    }
    ll operator*(const P &b) const
    {
        return (ll)x * b.y - (ll)y * b.x;
    }
    bool operator<(const P &b) const
    {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
    int orientation(P q, P r)
    {
        int val = (q.y - y) * (r.x - q.x) - (q.x - x) * (r.y - q.y);
        if (val == 0)
            return 0;             // thang hang
        return (val > 0) ? 1 : 2; // theo chieu kim dong ho va nguoc lai
    }
};
istream &operator>>(istream &cin, P &a)
{
    int _a, _b;
    cin >> _a >> _b;
    a = {_a, _b};
    return cin;
}
ostream &operator<<(ostream &cout, P &a)
{
    printf("%d %d\n", a.x, a.y);
    return cout;
}
int n(0);
P arr[4004];
map<P, bool> s;

void giftWrapping()
{
    int start = 1, p = 1, q, m(0);
    while (s[arr[start]])
        ++start;
    p = start;
    vector<P> hull;
    do
    {
        hull.pb(arr[p]);
        q = p + 1;
        forup(int, i, 1, n)
        {
            if (!s[arr[i]] && arr[p].orientation(arr[i], arr[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != start);
    for (P v : hull)
        s[v] = 1;
    forup(int, i, 1, n) if (!s[arr[i]]) arr[++m] = arr[i];
    n = m;
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n;
    forup(int, i, 1, n) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    int res(0);
    while (n > 2)
    {
        ++res;
        giftWrapping();
    }
    cout << res;
    return 0;
}