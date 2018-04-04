#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n,m,i,flagn,flagm;
long long N[maxn];
struct MM
{
	long long num;
	int code;
	bool res;
}M[maxn];

bool cmp1(MM a,MM b)
{
	return a.num<b.num;
}

bool cmp2(MM a,MM b)
{
	return a.code<b.code;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)
		scanf("%d",N+i);
	for(i=0;i<m;++i)
	{
		scanf("%d",&M[i].num);
		M[i].code=i;
	}
	sort(N,N+n);
	sort(M,M+m,cmp1);
	while(flagn<n&&flagm<m)
	{
		if(M[flagm].num==N[flagn])
		{
			M[flagm].res=1;
			flagm++;
		}
		else if(M[flagm].num>N[flagn])
			flagn++;
		else if(M[flagm].num<N[flagn])
			flagm++;
	}
	sort(M,M+m,cmp2);
	for(i=0;i<m;++i)
		if(M[i].res)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	return 0;
}
