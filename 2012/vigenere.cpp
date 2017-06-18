#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#define MAXN 1000
using namespace std;
char s1[MAXN+20],s2[MAXN+20];
int main()
{
    //freopen("vigenere.in","r",stdin);
    //freopen("vigenere.out","w",stdout);
    int i,j,k;
    int len1,len2;
    cin>>s1>>s2;
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0;i<len1;i++)
        s1[i]=toupper(s1[i]);
    for(i=0;i<len2;i++)
    {
        k = (toupper(s2[i])-s1[i%len1]+26)%26;
        if(islower(s2[i]))
            printf("%c",'a'+k);
        else
            printf("%c",'A'+k);
    }
    return 0;
}
