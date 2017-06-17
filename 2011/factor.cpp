#include <cstdio>
#include <iostream>
using namespace std;
int s[1002][1002];
int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
int main()
{
    //freopen("factor.in","r",stdin);
    //freopen("factor.out","w",stdout);
    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    a=a%10007;
    b=b%10007;
    s[0][0]=1;
    for(int i=0;i<=k;i++)
        s[i][0]=1;
    for(int i=0;i<=k;i++)
        s[i][i]=1;

    for(int i=2;i<=k;i++)
      for(int j=1;j<=i;j++)
        s[i][j]=(s[i-1][j]+s[i-1][j-1])%10007;
    int ans=s[k][m];
    for(int i=1;i<=n;i++)
        ans=(ans*a)%10007;
    for(int i=1;i<=m;i++)
        ans=(ans*b)%10007;
    cout<<ans%10007;
    return 0;
}
