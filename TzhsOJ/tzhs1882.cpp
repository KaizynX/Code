#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 100000+5;

int n,h[Maxn];
int flow[Maxn],fhigh[Maxn];
//条件：一高一低

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",h+i);
	}
	fhigh[1]=1;
	flow[1]=1;
	for(i=2;i<=n;++i)
	{
		if(h[i]>h[i-1])
			fhigh[i]=flow[i-1]+1;
		else fhigh[i]=fhigh[i-1];

		if(h[i]<h[i-1])
			flow[i]=fhigh[i-1]+1;
		else flow[i]=flow[i-1];
	}
	printf("%d\n",max(fhigh[n],flow[n]));
	return 0;
}
