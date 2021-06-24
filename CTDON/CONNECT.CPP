#include<bits/stdc++.h>
using namespace std;
void inti()
{
    freopen("connect.inp","r",stdin);
    freopen("connect.out","w",stdout);

}
int n,m,c,b,cha[100001];
vector<int>a[100001];
void dfs(int f)
{
    for (int i=0; i<a[f].size(); i++)
    {
        int v=a[f][i];
        if(cha[v]==0)
        {
            printf("%d ",v);
            cha[v]=1;
            dfs(v);
        }
    }
}
void solve()
{
    for (int i=1; i<=n; i++)
    {
        if(cha[i]==0)
        {
            printf("%d ", i);
            cha[i]=1;
            dfs(i);
            cout << "\n";
        }
    }
}
void nhap()
{
  scanf("%d %d",&n, &m);
  for (int i=1; i<=m; i++)
  {
      scanf("%d %d", &c, &b);
      a[c].push_back(b);
      a[b].push_back(c);
  }
  solve();
}
int main()
{
    inti();
    nhap();
}
