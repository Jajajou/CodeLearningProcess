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
}