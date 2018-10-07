#include <cstdio>
#include <iostream>
using namespace std;

int a,b,x,y;

void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
}

int main()
{
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	printf("%d\n",(x%b+b)%b);
	return 0;
}
