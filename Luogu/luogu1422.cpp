#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a;
	double m1,m2,m3,ans=0;
	m1=0.4463;//<=150
	m2=0.4663;//150 400
	m3=0.5663;//>400
	cin>>a;
	if(a>400)
	{
		ans+=(a-400)*m3;
		a=400;
	}
	if(a>150)
	{
		ans+=(a-150)*m2;
		a=150;
	}
	ans+=a*m1;
	printf("%.1f\n",ans);
	return 0;
} 
