#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=10000005;
char a;
int res,n,m;
bool f[maxn];
int read()
{
	a=getchar();
	res=0;
	while(a>='0'&&a<='9')
	{
		res=res*10+(a-'0');
		a=getchar();
	}
	return res;
}

inline void fun(int num)
{
	for(int i=num*2;i<=n;i+=num)
		f[i]=1;
}

bool sushu(int num)
{
	for(int i=2;i<=sqrt(num)+0.5;++i)
		if(num%i==0)
			return 0;
	return 1;
}

int main()
{
	int i,flag;
	n=read();
	m=read();
	for(i=2;i<=n;++i)
    {
        if(f[i])continue;
        flag=sushu(i);
        if(flag)
            fun(i);
        else
            f[i]=1;
    }
    f[2]=0;
	for(i=0;i<m;++i)
	{
		res=read();
		if(f[res])
			printf("NO\n");
		else
            printf("YES\n");
	}
	return 0;
}
