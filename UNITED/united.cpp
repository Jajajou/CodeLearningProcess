/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "united" //pls dont forget your task's name
#define maxn int(1e5) + 2
#define cut cout << endl
#define ll long long
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forup(i, start, end) for (int i = start; i <= end; ++i)
#define forupIn(i, start, end, in) for (int i = start; i <= end && cin >> in; ++i)
#define forupChar(i, start, end) for (char i = start; i <= end; ++i)
#define fordown(i, start, end) for (int i = start; i >= end; --i)
#define fordownChar(i, start, end) for (char i = start; i >= end; --i)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
using namespace std;
unsigned int val[maxn];
map<unsigned int, int> pos;
int n(0);
priority_queue<ll, vector<ll>, greater<ll>> f;

bool cmp(node &a, node &b)
{
    if (a.val != b.val)
        return a.val < b.val;
    if (a.pos != b.pos)
        return a.pos < b.pos;
    return 1 > 2;
}

void read()
{
    cin >> n;
    forup(i, 1, n)
    {
        cin >> val[i], pos[val[i]] = i;
        f.push(val[i]);
    }
    // sort(a + 1, a + n + 1, cmp);
}

void solve()
{
    int cp1(0), cp2(0);
    forup(i, 1, n)
    {
        cp1 = f.top(), f.pop();
        cout << cp.pos
                    cp2 = f.top(),
                    f.pop();
    }
}

int main()
{
    boost();
    Fin(name);
    Fout(name);
    read();
    solve();
}