/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "garden" //pls dont forget your task's name
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
    return x >> (pos - 1) & 1;
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
int d(0), n(0), r(0), res(0), cnt(0);
double pCircle(0);
ii pos[101], arr[101];

double distance(ii x, ii y)
{
    function<int(int)> sqr = [&sqr](int X)
    { return X * X; };
    return sqrt(sqr(x.fi - y.fi) + sqr(x.se - y.se));
}

bool cmp(ii x, ii y)
{
    x.fi -= arr[1].fi, y.fi -= arr[1].fi;
    x.se -= arr[1].se, y.se -= arr[1].se;
    if (x.fi * y.se == x.se * y.fi)
        return distance(arr[1], x) < distance(arr[1], y);
    return x.fi * y.se > x.se * y.fi;
}

void trade(int state)
{
    cnt = 0;
    forup(int, i, 1, n) if (getBit(state, i)) arr[++cnt] = pos[i];
    forup(int, i, 2, cnt) if ((arr[1].se > arr[i].se) || (arr[1].se == arr[i].se && arr[1].fi > arr[i].fi)) swap(arr[i], arr[1]);
    sort(arr + 2, arr + cnt + 1, cmp);
    function<bool(ii, ii, ii)> checkDirection = [&checkDirection](ii cp, ii x, ii y)
    {
        x.fi -= cp.fi, y.fi -= cp.fi;
        x.se -= cp.se, y.se -= cp.se;
        return x.fi * y.se > x.se * y.fi;
    };
    ii st[101];
    int top(0);
    forup(int, i, 1, cnt)
    {
        while (top > 1)
            if (checkDirection(st[top - 1], st[top], arr[i]))
                break;
            else
                --top;
        st[++top] = arr[i];
    }
    st[++top] = st[1];
    double cp(pCircle);
    forup(int, i, 1, top - 1) cp += (distance(st[i], st[i + 1]));
    res = (cp < d) ? max(res, cnt) : res;
}

void solve()
{
    cin >> d >> n >> r;
    pCircle = 2 * r * 3.14;
    forup(int, i, 1, n) cin >> pos[i].fi >> pos[i].se;
    res = 0;
    forup(int, state, 1, (1 << n) - 1) trade(state);
    return (void)(cout << res << endl);
}

int main()
{
    boost();
    /* #ifndef ONLINE_JUDGE
    IO();
    #endif */
    int t(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}