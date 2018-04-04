#include <iostream>
#include <cstdio>

using namespace std;
const int N=16+2;
int n;
struct tree
{
	int l,r;
}tr[N];

void print1(int i)
{
	if(i==0)return;
	printf("%d ",i);
	print1(tr[i].l);
	print1(tr[i].r);
}

void print2(int i)
{
	if(i==0)return;
	print2(tr[i].l);
	printf("%d ",i);
	print2(tr[i].r);
}

void print3(int i)
{
	if(i==0)return;
	print3(tr[i].l);
	print3(tr[i].r);
	printf("%d ",i);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&tr[i].l,&tr[i].r);
	print1(1);
	printf("\n");
	print2(1);
	printf("\n");
	print3(1);
	printf("\n");
	return 0;
}
