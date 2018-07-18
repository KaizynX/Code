#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 200+5;
const int WIN[][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int n,na,nb,nc;
int a[Maxn],b[Maxn];
int ca[Maxn*Maxn],cb[Maxn*Maxn];

inline void in();
inline int gcd(int a,int b);//最大公因数

void init()
{
	if(na>nb)
		nc=na*nb/gcd(na,nb);//一个周期,即最小公倍数
	else 
		nc=na*nb/gcd(nb,na);
	for(int i=0;i<nc;++i)
	{
		ca[i]=ca[i-1]+WIN[a[i%na]][b[i%nb]];
		cb[i]=cb[i-1]+WIN[b[i%nb]][a[i%na]];
	}
}

void solve()
{
	// n == t*nc + m 
	int t=n/nc,m=n%nc;
	int ansa,ansb;
	ansa=t*ca[nc-1]+ca[m-1];
	ansb=t*cb[nc-1]+cb[m-1];
	printf("%d %d\n",ansa,ansb);
}

int main()
{
	in();
	init();
	solve();
	return 0;
}

inline void in()
{
	int i;
	scanf("%d%d%d",&n,&na,&nb);
	for(i=0;i<na;++i)
		scanf("%d",a+i);
	for(i=0;i<nb;++i)
		scanf("%d",b+i);
}

inline int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
