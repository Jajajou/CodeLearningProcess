#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int l[N], r[N], v[N];

struct compare
{
    bool operator()(int i, int j) const
    {
        return v[i] < v[j] || (v[i] == v[j] && i < j);
    }
};

int main()
{
    freopen("bitstr.inp", "r", stdin);
    freopen("bitstr.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a;
    int res = n;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[i] == s[j])
            j++;
        a.push_back(j - i);
        i = j;
    }
    n = a.size();
    set<int, compare> seg;
    for (int cl = 1; cl <= 2; cl++)
        for (int cr = 1; cr <= 2; cr++)
        {
            seg.clear();
            for (int i = cl; i + cr < n; i++)
            {
                l[i] = r[i] = i;
                v[i] = a[i];
                seg.insert(i);
            }
            int cur = 0, num = seg.size() + 2;
            if (cl > 1)
                cur += a[0];
            if (cr > 1)
                cur += a.back();
            while (num > k && seg.size())
            {
                int x = *seg.begin();
                seg.erase(x);
                int y = r[x];
                cur += v[x];
                num -= 2;
                if (x == 0 || !seg.count(l[x - 1]))
                    seg.erase(y + 1);
                else if (!seg.count(y + 1))
                    seg.erase(l[x - 1]);
                else
                {
                    seg.erase(y + 1);
                    v[x] -= v[y + 1];
                    seg.erase(l[x - 1]);
                    v[l[x - 1]] -= v[x];
                    r[l[x - 1]] = r[y + 1];
                    l[r[y + 1]] = l[x - 1];
                    seg.insert(l[x - 1]);
                }
            }
            if (num <= k)
                res = min(res, cur);
        }
    cout << res;
}