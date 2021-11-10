/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "fib" // pls dont forget your task's name
#define qq 101001
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
int n(0), q(0);
class matrix
{
public:
    ll res[2][2];
    matrix() { res[0][0] = res[1][0] = res[0][1] = 1, res[1][1] = 0; }
    matrix(ll a, ll b, ll c, ll d) { res[0][0] = a, res[0][1] = b, res[1][0] = c, res[1][1] = d; }
    matrix operator%(const ll &k) { return matrix(res[0][0] % k, res[0][1] % k, res[1][0] % k, res[1][1] % k); }
    matrix operator*(const matrix &m)
    {
        return matrix(res[0][0] * m.res[0][0] % q + res[0][1] * m.res[1][0] % q,
                      res[0][0] * m.res[0][1] % q + res[0][1] * m.res[1][1] % q,
                      res[1][0] * m.res[0][0] % q + res[1][1] * m.res[1][0] % q,
                      res[1][0] * m.res[0][1] % q + res[1][1] * m.res[1][1] % q) %
               q;
    }
    matrix operator^=(const ll &n)
    {
        if (n <= 1)
            return matrix();
        matrix res = *this ^= (n >> 1);
        return n & 1 ? res * res * matrix() : res * res;
    }
};

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int T(0);
    cin >> T;
    while (T--)
    {
        bool ok(0);
        ll i(0);
        cin >> n >> i >> q;
        vector<int> pref(q + 1, 0);
        vector<ll> pos(q + 1, 0);
        pos[0] = i - 1;
        forup(ll, j, i, i + (1LL * q) - 1LL)
        {
            int x((matrix() ^= (j - 1)).res[0][0]);
            pref[j - i + 1] = pref[j - i] % q + x;
            pref[j - i + 1] %= q;
            if (pos[pref[j - i + 1]] != 0)
            {
                cout << j - pos[pref[j - i + 1]] << ' ';
                forup(ll, res, pos[pref[j - i + 1]] + 1, j) cout << res << ' ';
                ok = 1;
                break;
            }
            else
                pos[pref[j - i + 1]] = j;
        }
        if (!ok)
            cout << 0 << endl;
        else
            cut;
    }
    return 0;
}