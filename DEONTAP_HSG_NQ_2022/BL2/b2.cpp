#include <bits/stdc++.h>
using namespace std;
#define task "b2"
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
    int n(0), sum(0);
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; ++i)
        cin >> ar[i], sum += ar[i];
    if (sum & 1)
        cout << "Khong chia duoc";
    else
    {
        vector<int> res;
        for (int mask = 0; mask < (1 << n) - 1; ++mask)
        {
            int s(0);
            for (int i = 0; i < n; ++i)
                if (getBit(mask, i))
                    s += ar[i];
            if (s == sum / 2)
                res.push_back(mask);
        }
        cout << res.size() << endl;
        for (int v = 0; v < res.size(); ++v)
        {
            for (int i = 0; i < n; ++i)
                if (getBit(res[v], i))
                    cout << "A ";
                else
                    cout << "B ";
            cout << endl;
        }
    }
}