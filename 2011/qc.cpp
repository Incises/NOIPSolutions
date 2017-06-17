#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 200005
typedef long long int LL;
using namespace std;
LL n,m;
LL s;
LL sum;
LL w[MAXN],v[MAXN];
LL cnt[MAXN],sumv[MAXN];//保存前缀和
LL ops[MAXN][2];
void pre(int limit)//limit为当前枚举的W
{
	memset(cnt,0,sizeof(cnt));
	memset(sumv,0,sizeof(sumv));
	sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt[i] = cnt[i-1];
		sumv[i] = sumv[i-1];
		if(w[i] >= limit)
		{
			cnt[i]++;
			sumv[i] += v[i];
		}
	}
	for(int i = 1; i <= m; i++)
		sum += (cnt[ops[i][1]] - cnt[ops[i][0]-1]) * (sumv[ops[i][1]] - sumv[ops[i][0]-1]);
}
LL myllabs(LL x)
{
    return (x>0) ? x : -x;
}
int main()
{
	//freopen("qc.in","r",stdin);
	//freopen("qc.out","w",stdout);
	LL L = 1,R = 0;
	cin>>n>>m>>s;
	for(int i = 1; i <= n; i++)
	{
	    cin>>w[i]>>v[i];
		if(w[i] > R)
			R = w[i];
	}
	for(int i = 1; i <= m; i++)
	{
	    cin>>ops[i][0]>>ops[i][1];
	}
	LL mid;
	LL ans = 100000000000000LL;
	while(L <= R)
	{
		mid = (L+R)/2;
		pre(mid);//当前W的检验值
		if(ans > myllabs(s-sum))
			ans = myllabs(s-sum);
		if(sum < s)
			R = mid-1;
		if(sum > s)
			L = mid+1;
		if(sum == s)
			break;
	}
	cout<<ans;
	return 0;
}
