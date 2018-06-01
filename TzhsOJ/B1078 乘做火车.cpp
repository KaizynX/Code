#include<iostream>
using namespace std;
const int maxn=10000;

struct car
{
	int ua,uk,ta,tk;
}c[maxn];

int main()
{
	int a,n,m,x,k;
	cin>>a>>n>>m>>x;
	c[1].ua=1;
	c[1].ta=1;
	c[2].uk=1;
	c[2].ta=1;
	for(int i=3;i<n;++i)
	{
		c[i].ua=c[i-1].ua+c[i-2].ua;
		c[i].uk=c[i-1].uk+c[i-2].uk;
		c[i].ta=c[i-1].ta+c[i].ua-c[i-1].ua;
		c[i].tk=c[i-1].tk+c[i].uk-c[i-1].uk;
	}
	k=(m-c[n-1].ta*a)/c[n-1].tk;
	cout<<k<<endl;
	cout<<c[x].ta*a+c[x].tk*k<<endl;
	return 0;
}
