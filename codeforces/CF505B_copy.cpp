#include<bits/stdc++.h>
using namespace std;
long long a[150005],b[150005],ct1,ct2,g,ct;
int main()
{
	long long i,n;
	cin>>n;
	g=ct1=ct2=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		g= __gcd(g,a[i]*b[i]);
	}
	if(g==1) cout<<-1<<endl;
	else {
		for(i=1;i<=n;i++)
		{
			ct=__gcd(g,a[i]);
			if(ct==1)
			{
				ct=__gcd(g,b[i]);
			}
			g=ct;
		}
	cout<<g<<endl;
	}
	return 0;
}
