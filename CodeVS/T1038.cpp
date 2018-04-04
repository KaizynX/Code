#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	double a,b,c,d,u,v,m,n,w;
	cin>>a>>b>>c>>d;
	u=(9*a*b*c-27*a*a*d-2*b*b*b)/(54*a*a*a);
	v=sqrt(3*(4*a*c*c*v-b*b*c*c-18*a*b*c*d+27*a*a*d*f+4*b*b*b*d))/(18*a*a);
	if(abs(u+v)>=abs(u-v))m=pow(u+v,1.0/3);
	else m=pow(u-v,1.0/3);
	if(m==0)n=0;
	else n=(b*b-3*a*c)/(9*a*m);
	/*
	w=-1/2+sqrt(3)/2*i
	w*w=-1/2-sqrt(3)/2*i
	x1=m+n-b/(3*a)
	x2=w*m+w*w*n-b/(3*a)
	x3=w*w*m+w*n-b/(3*a)
	*/
	return 0;
}
