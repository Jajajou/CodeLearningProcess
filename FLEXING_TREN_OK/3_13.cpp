#include <bits/stdc++.h>
using namespace std;

// defining code area
#define name "3_13" // must not forget this!!!
#define lli long long

#define count_up(a, low, high) for (int(a) = (low); (a) <= (high); (a)++)
#define count_down(a, high, low) for (int(a) = (high); (a) >= (low); (a)--)
#define zerotopoint(a, point) for (int(a) = 0; a < (point); (a)++)

// coding area

void so9chuso()
{
    count_up(a, 1, 9)
    {
        zerotopoint(b, 10)
        {
            zerotopoint(c, 10)
            {
                zerotopoint(d, 10)
                {
                    zerotopoint(e, 10)
                    {
                        zerotopoint(f, 10)
                        {
                            zerotopoint(g, 10)
                            {
                                zerotopoint(h, 10)
                                {
                                    zerotopoint(i, 10)
                                    {
                                        int tong = 0;
                                        tong = a + b + c + d + e + f + g + h + i;
                                        if (tong % 5 == 0)
                                        {
                                            cerr << a * 100000000 + b * 10000000 + c * 1000000 + d * 100000 + e * 10000 + f * 1000 + g * 100 + h * 10 + i;
                                            cerr << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool checkPalin(lli n)
{
    vector<int> a;
    while (n)
    {
        a.push_back(n % 10);
        n /= 10;
    }
    int sz = (int)a.size();
    for (int i = 0; i < sz; i++)
    {
        if (a[i] != a[sz - i - 1])
            return 0;
    }
    return 1;
}
bool kiemtrathuannghich(lli n)
{
    lli temp1 = n;
    int a[9];
    int i = 0;
    while (temp1 > 0)
    {
        a[i] = temp1 % 10;
        temp1 /= 10;
        i++;
    }

    lli temp2 = n;
    int b[9];
    int j = 8;
    while (temp2 > 0)
    {
        b[j] = temp2 % 10;
        temp2 /= 10;
        i--;
    }

    int dem = 0;
    for (int k = 0; k < 9; k++)
    {
        if (a[i] == b[j])
            dem++;
    }
    if (dem == 9)
        return true;
    else
        return false;
}

bool kiemtrasochan(lli n)
{
    int temp;
    while (n)
    {
        temp = n % 10;

        if (temp & 1)
            return 0;
        n /= 10;
    }
    return 1;
}

bool tongchia5(lli n)
{
    int tong = 0;
    while (n)
    {
        tong += n % 10;
        n /= 10;
    }
    return (tong % 5 == 0);
}
void input()
{
}

void output()
{
    for (int i = 100000000; i <= 999999998; i += 2)
    {
        if (checkPalin(i) && kiemtrasochan(i) && tongchia5(i))
        {
            cout << i << " ; ";
        }
    }
}

int main()
{
    // input();
    output();
}