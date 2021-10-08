/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define name "" //pls dont forget your task's name
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
int n, m, cp(0), c(0);
string res[maxn], tmp;
vector<int> a, b, f;
vector<ii> k, x;

int main()
{
    boost();
    /* #ifndef ONLINE_JUDGE
    IO();
#endif */
    ifstream input("D:\\C++\\TINHTIEN\\INP.TXT");
    fstream output2, output3;
    output2.open("D:\\C++\\TINHTIEN\\OUT2.TXT", ios::out);
    output3.open("D:\\C++\\TINHTIEN\\OUT3.TXT", ios::out);
    //input
    input >> n >> m;
    a.resize(n);
    b.resize(n);
    f.resize(n);
    k.resize(m);
    x.resize(n);
    forup(int, i, 0, n - 1) input >> a[i] >> b[i];
    forup(int, i, 0, m - 1) input >> k[i].fi, k[i].se = i;
    input.close(); //close input

    //screen ouput
    cout << n << ' ' << m << '\n';
    forup(int, i, 0, n - 1) cout << a[i] << ' ' << b[i] << '\n';
    forup(int, i, 0, m - 1) cout << k[i].fi << '\n';

    //output2

    //output3

    //close IO
    output2.close(); //close ouput2
    output3.close(); //close ouput3
    return 0;
}