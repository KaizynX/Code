#include <iostream>
using namespace std;
char a[40];
long long ans;
int n,k;

long long change(int x,int y)
{
	long long res=0;
	for(int i=x;i<=y;++i)
		res=res*10+(a[i]-'0');
	return res;
}

void solve(int k,int p,int sum)
{
	if(k==0)
	{
		sum*=change(p,n-1);
		if(sum>ans)ans=sum;
		return;
	}
	for(int i=p;i<n-k;++i)
		solve(k-1,i+1,sum*change(p,i));
}

int main()
{
	cin>>n>>k;
	for(int i=0;i<n;++i)
		cin>>a[i];
	solve(k,0,1);
	cout<<ans<<endl;
}
