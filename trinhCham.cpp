#include <bits/stdc++.h>
using namespace std;

const string task = "rc";
const string trinhChamUrl = "D:\\C++\\TEST\\";
const string taskUrl = "D:\\C++\\CSES_GRAPH_ALGORITHMS\\ROAD_CONSTRUCTRION\\";
const int testN = 100;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

typedef unsigned long long ll;
const ll maxx = 100;
const ll minn = 1;

ll randd(ll l, ll r)
{
    assert(l <= r);
    return l + rd() * 1LL * rd() % (r - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= testN; iTest++)
    {
        ofstream inp((trinhChamUrl + task + ".inp").c_str());
        ll n(randd(minn, maxx)), m(randd(minn, maxx));
        if (m < n)
            m = n - m;
        else
            m = m - n;
        inp << n << ' ' << m << endl;
        for (ll i(0); i < m; ++i)
        {
            ll u(randd(minn, n)), v(randd(minn, n));
            inp << u << ' ' << v << endl;
        }
        inp.close();
        system((taskUrl + task + ".exe").c_str());
        system((trinhChamUrl + "test.exe").c_str());
        if (system(("fc " + taskUrl + task + ".out " + trinhChamUrl + task + ".out").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}