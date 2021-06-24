#include <bits/stdc++.h>
#define maxn 1000005
#define ui unsigned int
#define forUp(i, start, end) for (int i = start; i <= end; i++)
#define forDown(i, start, end) for (int i = start; i >= end; i--)
using namespace std;

long long n, t[maxn], maxx[maxn], maxy[maxn], minx[maxn], miny[maxn];

void read()
{
    scanf("%d", &n);
    forUp(i, 1, n)
    {
        scanf("%lld", &t[i]);
        if (i == 2 && t[i - 1] * -1 == t[i])
        {
            cout << '0';
            exit(0);
        }
    }
}

void solve()
{
    // tim max x
    maxx[1] = t[1];
    forUp(i, 2, n)
    {
        if (t[i] > maxx[i - 1])
            maxx[i] = t[i];
        else
            maxx[i] = maxx[i - 1];
    }

    // tim min x
    minx[1] = t[1];
    forUp(i, 2, n)
    {
        if (t[i] < minx[i - 1])
            minx[i] = t[i];
        else
            minx[i] = minx[i - 1];
    }

    // tim max y
    maxy[n] = t[n];
    forDown(i, n - 1, 1)
    {
        if (t[i] > maxy[i + 1])
            maxy[i] = t[i];
        else
            maxy[i] = maxy[i + 1];
    }

    // tim min y
    miny[n] = t[n];
    forDown(i, n - 1, 1)
    {
        if (t[i] < miny[i + 1])
            miny[i] = t[i];
        else
            miny[i] = miny[i + 1];
    }

    long long d(0);
    forUp(i, 2, n - 1)
    {
        d = max(d, (maxx[i - 1] - t[i]) * (t[i] - miny[i + 1]));
        d = max(d, (minx[i - 1] - t[i]) * (t[i] - maxy[i + 1]));
    }
    cout << d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("maxenergy.inp", "r", stdin);
    freopen("maxenergy.out", "w", stdout);
    read();
    solve();
}