#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
int n,t,a[maxn];
long long x[maxn];

int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)
		scanf("%ld",&x+i);
	for(int i=1;i<=n;++i)
		scanf("%d",&a+i);
	return 0;
} 
