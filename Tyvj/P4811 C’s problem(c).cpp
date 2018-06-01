#include <iostream>
#include <cstdio>
using namespace std;
int n,len;
long long sum;
int ans[25],res[25];
int main()
{
	int i,j,a,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a);
		sum+=a;
	}
	while(sum)
	{
		ans[++len]=sum%10;
		sum/=10;
	}
	for(i=1;i<=len;++i)
		for(j=1;j<=len;++j)
			res[i+j-1]+=ans[i]*ans[j];
	len*=2;
	for(i=1;i<len;i++)
	{
		res[i+1]+=res[i]/10;
		res[i]%=10;
	}
	for(i=len;i>0;--i)
	{
		if(res[i])flag=1;
		if(res[i]==0&&flag==0)continue;
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}
