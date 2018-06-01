#include <cstdio>
#include <iostream>
using namespace std;
const int mo = 10007;
const int Maxk = 1000+5;

int a,b,k,n,m;
int x[Maxk][Maxk];
//x[n][m]表示X^n*Y^m的系数
int main()
{
	int ik,in,im;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	a%=mo;
	b%=mo;
	// +1 防止 0-1 越界
	k+=2;
	n++;
	m++;

	x[1+1][0+1]=a;//k(X)=a  aX
	x[0+1][1+1]=b;//k(Y)=b  bY
	for(ik=2+1+1;ik<=k;++ik)
	{
		for(in=0+1;in<ik;++in)//in (1~ik-1)
		{
			im=ik-in;
			//k(X^n*Y^m) = k(X^n-1*Y^m)*aX + k(X^n*Y^m-1)*by
			x[in][im]=(x[in-1][im]*a+x[in][im-1]*b)%mo;
			if(in==n && im==m)
			{
				printf("%d\n",x[n][m]);
				return 0;
			}
		}
	}
	return 0;
}
