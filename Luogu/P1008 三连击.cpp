#include <iostream>
#include <cstdio>

using namespace std;

int vis[10];

inline bool push(int i)
{
	if(vis[i])return 0;
	vis[i]=1;
	return 1;
}

inline void pd(int n1)
{
	int vis2[10]={0};
	int n2,n3,cur;
	n2=2*n1;
	n3=3*n1;
	if(n3>999)
		return;
	vis2[n1%10]=1;
	vis2[(n1/10)%10]=1;
	vis2[n1/100]=1;
	while(n2>0)
	{
		cur=n2%10;
		if(vis2[cur]==1||cur==0)return;
		vis2[cur]=1;
		n2/=10;
	}
	while(n3>0)
	{
		cur=n3%10;
		if(vis2[cur]==1||cur==0)return;
		vis2[cur]=1;
		n3/=10;
	}
	printf("%d %d %d\n",n1,n1*2,n1*3);
}

int main()
{
	int i1,i2,i3;
	for(i1=1;i1<=4;++i1)
	{
		if(push(i1)==0)continue;
		for(i2=1;i2<=9;++i2)
		{
			if(push(i2)==0)continue;
			for(i3=1;i3<=9;++i3)
			{
				if(push(i3)==0)continue;
				pd(i1*100+i2*10+i3);
				vis[i3]=0;
			}
			vis[i2]=0;
		}
		vis[i1]=0;
	}
	return 0;
} 
