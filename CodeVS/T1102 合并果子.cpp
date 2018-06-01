#include <iostream>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	int n,a,b,ans=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		q.push(a);
	}
	for(int i=1;i<n;++i)
	{
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
}
