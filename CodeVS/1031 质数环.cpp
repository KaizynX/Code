#include <iostream>
#include <cstdio>
using namespace std;
const int N=17+3;
int n,a[N],vis[N],b[N];

void print()
{
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	printf("\n");
}

void bfs(int cur)
{
	if(cur>n)
	{
		if(b[1+a[cur-1]]==1)
			print();
		return;
	}
	for(int i=2;i<=n;++i)
		if(b[i+a[cur-1]]==1&&vis[i]==0)
		{
			vis[i]=1;
			a[cur]=i;
			bfs(cur+1);
			vis[i]=0;
		}			
}

int main()
{
	scanf("%d",&n);
	if(n%2!=0)
		return 0;
	b[2]=1;
	b[3]=1;
	b[5]=1;
	b[7]=1;
	b[11]=1;
	b[13]=1;
	b[17]=1;
	b[19]=1;
	b[23]=1;
	b[29]=1;
	b[31]=1;
	a[1]=1;
	//vis[1]=1;
	bfs(2);
	return 0;
}
