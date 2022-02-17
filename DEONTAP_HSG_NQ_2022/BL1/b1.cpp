#include <bits/stdc++.h>
using namespace std;
#define task "b1"
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
    int n(0), t(0), m(0);
    cin >> n >> t >> m;
    vector<int> ar(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> ar[i], pref[i] = pref[i - 1] + ar[i];
    ll res(0);
    res = (t + m - 1 > n) ? (1LL * pref[n] - 1LL * pref[t - 1]) + 1LL * pref[t + m - 1 - n] : 1LL * pref[t + m - 1] - 1LL * pref[t - 1];
    cout << res;
}