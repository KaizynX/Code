#include <iostream>
using namespace std;
int main()
{
	int n,a,i,ans=0;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a;
		if(a%2)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
