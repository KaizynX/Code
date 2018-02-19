#include <iostream>

using namespace std;
long long a,b,k;
long long ans=9223372036854775807;

void solve(long long now,long long step)
{
	if(now==a)
	{
		//ans=min(ans,step);
		if(step<ans)ans=step;
		return;
	}
	else if(now>a)
	{
		if(now/k>=a)
		{
			int c=now % k;
			solve((now-c)/k,step+c+1);
		}
		else 
		{
			solve(a,now-a+step);
		}
	}
}

int main()
{
	cin>>a>>b>>k;
	if(k==0||k==1)
	{
		cout<<b-a<<endl;
		return 0;
	}
	else solve(b,0);
	cout<<ans<<endl;
	return 0;
}
