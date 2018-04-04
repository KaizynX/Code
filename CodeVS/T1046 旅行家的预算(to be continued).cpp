#include <iostream>
#include <algorithm>
using namespace std;

struct oil
{
	double d,p,rest;
}o[101];

struct used
{
	double x,y;
}u[101];

int cmp(oil a,oil b)
{
	return a.p<b.p;
}

int main()
{
	double d1,c,d2,p,sum=0,ans=0;
	int n;
	cin>>d1>>c>>d2>>p>>n;
	o[0].d=0;o[0].p=p;o[0].rest=0;//first oil station
	for(int i=1;i<=n;++i)
	{
		cin>>o[i].d>>o[i].p;
		o[i].rest=0;
	}
	sort(o,o+n+1,cmp);
	for(int i=0;i<=n;++i)
	{
		if(d1-o[i].d>c*d2)//give full oil is too much
		{
			//d1-o[i]
		}
		else 
		{
			
		}
		
		if(sum>=d1)break;
	}
	if(sum>=d1)cout<<ans<<endl;
	else cout<<"No Solution"<<endl;
	return 0;
}
