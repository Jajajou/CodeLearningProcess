#include <bits/stdc++.h>
using namespace std;
#define task "b3"
#define boostIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;
typedef pair<int, int> ii;
template <class val>
val getBit(val n, val pos)
{
    return (n >> pos) & 1;
}

const void IO()
{
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
}

int main()
{
    boostIO();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int m(0), n(0);
    cin >> m >> n;
    vector<int> tables(m), guests(n);
    for (int i = 0; i < m; ++i)
        cin >> tables[i];
    sort(tables.begin(), tables.end());
    for (int i = 0; i < n; ++i)
        cin >> guests[i];
    sort(guests.begin(), guests.end());
    int j(0), res(0);
    for (int i = 0; i < n; ++i)
    {
        while (guests[i] > tables[j])
            ++j;
        res += abs(guests[i] - tables[j++]);
    }
    cout << res;
}