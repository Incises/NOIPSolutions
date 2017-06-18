#include<iostream>
#include<cstdio>
using namespace std;
int a,b,x,y,ans;
int ExEuc(int a,int b)
    {
    //Bezout
    //ax+by=1
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    ans = ExEuc(b,a%b);
    int tmp = y;
    y = x-(a/b)*y;
    x = tmp;
    return ans;
}
int main()
{
    //freopen("mod.in","r",stdin);
	//freopen("mod.out","w",stdout);
	cin>>a>>b;
    ExEuc(a,b);
    x = (x%b+b)%b;
    cout<<x;
    return 0;
}
