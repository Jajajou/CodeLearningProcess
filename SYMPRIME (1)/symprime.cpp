#include <bits/stdc++.h>
#define maxx 20000005
#define ll long long
using namespace std;
bool nt[maxx], dx[maxx];
ll a[maxx], n, m = 1;
int t;

void sangnt()
{
	memset(nt, true, sizeof(nt));
	nt[1] = false;
	ll i = 2;
	while (i <= trunc(sqrt(maxx)))
	{
		while (!nt[i])
			++i;
		for (ll j = i; j <= maxx / i; ++j)
			nt[j * i] = false;
		++i;
	}
	//
	ll j = 2;
	while (j <= maxx)
	{
		if (nt[j])
		{
			a[m] = j;
			++m;
		}
		++j;
	}
}

double tbc(ll x, ll y)
{
	return (double_t(x) + double_t(y)) / 2;
}

void taobangdx()
{
	memset(dx, false, sizeof(dx));
	for (ll i = 2; i <= m; ++i)
	{
		double t = tbc(a[i - 1], a[i + 1]);
		if (t == double_t(a[i]))
			dx[a[i]] = true;
	}
}

void solve()
{
	sangnt();
	taobangdx();
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		scanf("%lld", &n);
		if (dx[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int main()
{
	freopen("symprime.inp", "r", stdin);
	freopen("symprime.out", "w", stdout);
	solve();
	// system("pause");
	return (0);
}