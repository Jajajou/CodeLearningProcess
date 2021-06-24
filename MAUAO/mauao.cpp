#include <bits/stdc++.h>
#define maxx 100005
#define forup(i, start, end) for (int i = start; i <= end; i++)
using namespace std;
struct arr
{
    int fcash, stt, rcash;
};
int m, n;
long long s = 0;
arr a[maxx];

void qSort(int l, int r)
{
    arr mid = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i].fcash < mid.fcash)
            ++i;
        while (a[i].fcash > mid.fcash)
            --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (l < j)
        qSort(l, j);
    if (i < r)
        qSort(i, r);
}

void qSort2(int l, int r)
{
    arr mid = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i].stt < mid.stt)
            ++i;
        while (a[i].stt > mid.stt)
            --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (l < j)
        qSort2(l, j);
    if (i < r)
        qSort2(i, r);
}

void solve()
{
    //nhap
    cin >> n >> m;
    forup(i, 1, n)
    {
        cin >> a[i].fcash;
        s += a[i].fcash;
        a[i].stt = i;
    }
    //th khong chia duoc
    if (s < m)
    {
        cout << "-1";
        exit(0);
    }
    //th chia duoc
    qSort(1, n);
    // forup(i,1,n) cout << a[i].fcash << ' '; cout <<endl;
    int tb = m / n, tmp = n;
    forup(i, 1, n)
    {
        if (a[i].fcash < tb)
        {
            a[i].rcash = a[i].fcash;
            --tmp;
            m -= a[i].fcash;
        }
        else
        {
            a[i].rcash = tb;
            m -= tb;
            --tmp;
        }
        if (tmp == 0)
            break;
        tb = m / tmp;
        s = m % tmp;
    }
    //xuat
    qSort2(1, n);
    forup(i, 1, n) cout << a[i].stt << ' ';
    forup(i, 1, n) cout << a[i].rcash << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("share948.inp", "r", stdin);
    freopen("share948.out", "w", stdout);
    solve();
    // system("pause");
    return 0;
}