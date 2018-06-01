#include <iostream>
using namespace std;
int n,k,ans;

void solve (int s,int t,int last)
{
	if(t==k)
	{
		if(s==0)ans++;
		return;
	}
	for(int i=last;i<=s;i++)
		solve(s-i,t+1,i);
}

int main()
{
	cin>>n>>k;
	solve(n,0,1);
	cout<<ans<<endl;
} 
