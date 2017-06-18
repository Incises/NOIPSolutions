#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int a[1001];//左手
int b[1001];//右手
int ka,kb;
int ans[20000],t[20000],len_a;// ans 及其长度
int len_t,tt[20000],t2[20000],len;//用于高精度乘除
void _qst_ab(int l,int r)
{
    //快速排序
    int i=l,j=r,ma=a[(i+j)>>1],mb=b[(i+j)>>1];
    while(i<=j)
    {
        while(a[i]*b[i]<ma*mb) i++;
        while(a[j]*b[j]>ma*mb) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }
    if(l<j) _qst_ab(l,j);
    if(i<r) _qst_ab(i,r);
}
void _init()
{
    cin>>N>>a[0]>>b[0];
    for(int i=1;i<=N;i++)
        cin>>a[i]>>b[i];
}
void _get_t(int Left,int Right)
{
    for(int i=1;i<=len_t;i++)
    {
        tt[i]+=t[i]*Left;
        tt[i+1]+=tt[i]/10;
        tt[i]%=10;
    }
    len_t++;
    while(tt[len_t]>=10)
    {
        tt[len_t+1]=tt[len_t]/10;
        tt[len_t]%=10;
        len_t++;
    }
    while(len_t>1&&tt[len_t]==0)
        len_t--;
    len=len_t;
    memcpy(t,tt,sizeof(tt));
    memset(tt,0,sizeof(tt));
    for(int i=1,j=len;i<=len;i++,j--)
        t2[i]=t[j];
    int x=0,y=0;
    for(int i=1;i<=len;i++)
    {
        y=x*10+t2[i];
        tt[i]=y/Right;
        x=y%Right;
    }
    x=1;
    while(x<len&&tt[x]==0)
        x++;
    memset(t2,0,sizeof(t2));
    for(int i=1,j=x;j<=len;i++,j++)
        t2[i]=tt[j];
    memcpy(tt,t2,sizeof(t2));
    len=len+1-x;
}
bool _cmp()
{
    if(len>len_a) return true;
    if(len<len_a) return false;
    for(int i=1;i<=len;i++)
    {
        if(ans[i]<tt[i]) return true;
        if(ans[i]>tt[i]) return false;
    }
    return false;
}
void _solve()
{
    _qst_ab(1,N);
    t[1]=1;
    len_t=1;
    for(int i=1;i<=N;i++)
    {
        memset(tt,0,sizeof(tt));
        len=0;
        _get_t(a[i-1],b[i]);
        if(_cmp())
        {
            memcpy(ans,tt,sizeof(tt));
            len_a=len;
        }
    }
    for(int i=1;i<=len_a;i++)
        cout<<ans[i];
}
int main()
{
    //freopen("game.in","r",stdin);
    //freopen("game.out","w",stdout);
    _init();
    _solve();
    return 0;
}
