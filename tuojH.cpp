#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x,y;
	scanf("%lf",&x);
	if(x>0 && x<1)
		y=10-x*x;
	else if(x>=1 && x<=4)
		y=10-x;
	else if(x>4 && x<25)
		y=10-2*sqrt(x);
	printf("%.2f\n",y);
	return 0;
}
