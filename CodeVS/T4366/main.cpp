#include <iostream>
#include <cstdio>

using namespace std;
const int Maxn=10000001;
int c[Maxn];

void read(int &a)//传说中的输入优化
{
	a=0;int h=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')	h=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	a*=h;
}

int main()
{
    int n,m,ins,a,b;
    long long big=0;
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(c[i]);
        if(c[i]>big)big=c[i];
    }
    read(m);
    for(int i=0;i<m;i++)
    {
        read(ins);
        if(ins==1)
        {
            read(a);
            read(b);
            c[a]+=b;
            if(c[a]>big)big=c[a];
        }
        else
        {
            printf("%ld\n",big);
        }
    }
    return 0;
}
