#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    //freopen("carpet.in","r",stdin);
    //freopen("carpet.out","w",stdout);
    int n,a[10001],b[10001],x[10001],y[10001];
    cin>>n;
    int i;
    for(i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>x[i]>>y[i];
    }
    int xi,yi;
    cin>>xi>>yi;
    int j;
    for(j=n;j>0;j--)
    {
        if(  a[j]<=xi
           &&xi<=(a[j]+x[j])
           &&b[j]<=yi
           &&yi<=(b[j]+y[j]))
        {
            cout<<j;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
