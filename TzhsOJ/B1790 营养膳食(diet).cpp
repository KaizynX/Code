#include <iostream>
#include <algorithm>
using namespace std;
int mk[101],nk[101];

struct food
{
	int v,k;
}f[200];

bool cmp(food a,food b)
{
	return a.v>b.v;
}

int main()
{
	int n,m,k,ans=0,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=k;++i)
		cin>>mk[i];
	for(int i=0;i<n;++i)
		cin>>f[i].v>>f[i].k;
	sort(f,f+n,cmp);
	for(int i=0;i<n;++i)
	{
		if(nk[f[i].k]<mk[f[i].k])
		{
			ans+=f[i].v;
			sum++;
			nk[f[i].k]++;
		}
		if(sum==m)break;
	}
	cout<<ans<<endl;
	return 0;
}
