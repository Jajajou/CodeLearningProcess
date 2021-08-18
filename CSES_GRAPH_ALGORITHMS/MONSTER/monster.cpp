
#include <bits/stdc++.h>
using namespace std;
#define name "monster" //pls dont forget your task's name
#define maxn 1001
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
int n, m, neighborX[4] = {1, -1, 0, 0}, neighborY[4] = {0, 0, 1, -1};
queue<ii> q;
ii A, from[maxn][maxn];
ll paths[maxn][maxn];
string ans, guide("UDLR");
bool possible(0);

void retrace(ii node)
{
    ii u = from[node.fi][node.se];
    if (u == ii(0, 0))
        return;
    forup(int, k, 0, 3) if (node.fi + neighborX[k] == u.fi && node.se + neighborY[k] == u.se)
        ans.pb(guide[k]);
    retrace(u);
}

bool check(ii u, int k) { return paths[u.fi][u.se] + 1 < paths[u.fi + neighborX[k]][u.se + neighborY[k]]; }
bool mode(0);
void bfs()
{
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        forup(int, k, 0, 3) if (check(u, k))
        {
            q.push({u.fi + neighborX[k], u.se + neighborY[k]});
            paths[u.fi + neighborX[k]][u.se + neighborY[k]] = paths[u.fi][u.se] + 1;
            from[u.fi + neighborX[k]][u.se + neighborY[k]] = u;
        }
        if (mode && (u.fi == 1 || u.se == 1 || u.fi == n || u.se == m))
        {
            cout << "YES" << endl;
            cout << paths[u.fi][u.se] << endl;
            retrace(u);
            possible = true;
            return;
        }
    }
}

int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    cin >> n >> m;
    forup(int, i, 1, n)
    {
        string s;
        cin >> s;
        forup(int, j, 1, m)
        {
            paths[i][j] = INT_MAX;
            if (s[j - 1] == '#')
                paths[i][j] = 0;
            if (s[j - 1] == 'M')
                q.push({i, j}), paths[i][j] = 0;
            if (s[j - 1] == 'A')
                A = {i, j};
        }
    }
    bfs();
    mode = 1;
    from[A.fi][A.se] = ii(0, 0);
    paths[A.fi][A.se] = 0;
    q.push(A);
    bfs();
    if (possible)
    {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else
        cout << "NO" << endl;
    return 0;
}