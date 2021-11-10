#include <bits/stdc++.h>
using namespace std;

const string task = "voi21_bonus";
const string trinhChamUrl = "D:\\C++\\TEST\\";
const string taskUrl = "D:\\C++\\VOI21_BONUS\\";
const int testN = 100;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

typedef unsigned long long ll;
const ll maxx = 100;
const ll minn = 4;

ll randd(ll l, ll r)
{
    assert(l <= r);
    return l + rd() * 1LL * rd() % (r - l + 1);
}

string gen_random(int len)
{
    string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    static const char upperCase[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const char lowerCase[] =
        "abcdefghijklmnopqrstuvwxyz";
    static const char number[] =
        "0123456789";
    for (int i = 0; i < len; ++i)
        s += upperCase[randd(0, 25)];
    return s;
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= testN; iTest++)
    {
        ofstream inp((trinhChamUrl + task + ".inp").c_str());
        ll n(randd(3, 100)), m(randd(3, 100));
        inp << n << ' ' << m << endl;
        for (int i(0); i < n; ++i)
            inp << randd(1, 1000) << '\n'
                << gen_random(randd(1, 100)) << '\n';
        inp.close();
        system((trinhChamUrl + "test.exe").c_str());
        system((taskUrl + task + ".exe").c_str());
        if (system(("fc " + taskUrl + task + ".out " + trinhChamUrl + task + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}