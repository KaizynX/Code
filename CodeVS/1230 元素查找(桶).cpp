#include <iostream>
using namespace std;
const int maxn=100000001;
bool a[maxn];
int n,m,i;
long long b;
int main()
{
	cin>>n>>m;
	for(i=0;i<n;++i)
	{
		cin>>b;
		a[b]=1;
	}
	for(i=0;i<m;++i)
	{
		cin>>b;
		if(a[b])
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}
