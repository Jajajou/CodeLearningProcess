/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "newton" //pls dont forget your task's name
#define maxn 101
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
const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
int n(0), catRoom(0), ratRoom(0), catPath[maxn] = {}, ratPath[maxn] = {};
bool visited[maxn] = {};
vector<int> catG[maxn], ratG[maxn];

void read()
{
    cin >> n >> catRoom >> ratRoom;
    int m(0), u(0), v(0);
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        catG[u].push_back(v);
    }
    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        ratG[u].push_back(v);
    }
    forup(i, 1, n)
    {
        sort(ratG[i].begin(), ratG[i].end());
    }
    catPath[catRoom] = ratPath[ratRoom] = n + 1;
}

void catDfs(int u)
{
    for (int v : catG[u])
    {
        if (!catPath[v])
        {
            catPath[v] = u;
            catDfs(v);
        }
    }
}

void ratDfs(int u)
{
    for (int v : ratG[u])
    {
        if (!ratPath[v])
        {
            ratPath[v] = u;
            ratDfs(v);
        }
    }
}

void prob1()
{
    vector<int> res;
    catDfs(catRoom);
    ratDfs(ratRoom);
    forup(i, 1, n)
    {
        if (catPath[i] && ratPath[i])
        {
            res.push_back(i);
            visited[i] = 1;
        }
    }
    cout << res.size() << endl;
    for (int i : res)
        cout << i << endl;
}

int k(0), res[maxn] = {};
void bf(int f)
{
    k = 0;
    while (f != n + 1)
    {
        res[++k] = f;
        f = ratPath[f];
    }
}

void dfs(int u)
{
    if (k > 2)
        return;
    for (int v : ratG[u])
    {
        if (v == ratRoom)
        {
            bf(u);
            if (k > 2)
                return;
        }
        if (!visited[v] && !ratPath[v])
        {
            ratPath[v] = u;
            dfs(v);
        }
    }
}

void prob2()
{
    forup(i, 1, n) ratPath[i] = 0;
    catPath[catRoom] = ratPath[ratRoom] = n + 1;
    dfs(ratRoom);
    if (k > 2)
    {
        cout << k << endl;
        fordown(i, k, 1) cout << res[i] << endl;
    }
    else
        cout << 0;
}

int main()
{
    boost();
    IO();
    read();
    prob1();
    prob2();
}