/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
using namespace std;
#define name "coc" //pls dont forget your task's name
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
struct Tree
{
    int m, d;
    Tree *L, *R;
    Tree(int _m) : m(_m), d(0), L(0), R(0) {}
};

void push(Tree *T)
{
    T->m = max(T->m, T->d);
    if (T->L)
        T->L->d = max(T->L->d, T->d);
    if (T->R)
        T->R->d = max(T->R->d, T->d);
}

int get(Tree *T, int tl, int tr, int i)
{
    push(T);
    int tx = (tl + tr) >> 1;
    if (T->L && i < tx)
        return max(get(T->L, tl, tx, i), T->m);
    if (T->R && i >= tx)
        return max(get(T->R, tx, tr, i), T->m);
    return T->m;
}

void upd(Tree *T, int tl, int tr, int l, int r, int d)
{
    push(T);
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r)
    {
        T->d = d;
        return;
    }
    if (!T->L)
    {
        T->L = new Tree(T->m);
        T->R = new Tree(T->m);
    }
    int tx = (tl + tr) >> 1;
    upd(T->L, tl, tx, l, r, d);
    upd(T->R, tx, tr, l, r, d);
}
int n, q, x, y, z;
char c;
Tree *tv, *th;

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif

    scanf("%d %d", &n, &q);
    tv = new Tree(0);
    th = new Tree(0);

    for (int qq = 0; qq < q; qq++)
    {
        scanf("%d %d %c", &x, &y, &c);
        if (c == 'U')
        {
            z = get(tv, 1, n + 1, x);
            printf("z: %d\n", z);
            printf("%d\n", y - z);
            upd(th, 1, n + 1, z + 1, y + 1, x);
            upd(tv, 1, n + 1, x, x + 1, y);
        }
        else
        {
            z = get(th, 1, n + 1, y);
            printf("z: %d\n", z);
            printf("%d\n", x - z);
            upd(tv, 1, n + 1, z + 1, x + 1, y);
            upd(th, 1, n + 1, y, y + 1, x);
        }
    }

    return 0;
}