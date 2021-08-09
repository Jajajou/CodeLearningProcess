/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "twoSet" //pls dont forget your task's name
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

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    ll n(0);
    cin >> n;
    if ((n * (n + 1) >> 1) & 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        set<ll> s1, s2;
        forup(ll, i, 1, n) s1.insert(i);
        ll tmp(n), target(((n * (n + 1)) >> 1) >> 1);
        while (!s1.count(target))
        {
            target -= tmp;
            s1.erase(tmp);
            s2.insert(tmp);
            --tmp;
        }
        s1.erase(target);
        s2.insert(target);
        cout << s1.size() << endl;
        for (int v : s1)
            cout << v << " ";
        cout << "\n"
             << s2.size() << endl;
        for (int v : s2)
            cout << v << " ";
    }
    return 0;
}