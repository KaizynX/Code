#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
long long a[maxn];
int n,m;
struct tree
{
	int l,r;
	long long add,sum;
}tr[maxn*4];

void build_tree(int x,int y,int i)
{
	tr[i].l=x;
	tr[i].r=y;
	if(x==y)
	{
		tr[i].sum=a[x];
		return;
	}
	int mid=(x+y)/2;
	build_tree(x,mid,i*2);
	build_tree(mid+1,y,i*2+1);
	tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

inline void push_down(int i)
{
	if(tr[i].add)
	{
		int len=tr[i].r-tr[i].l+1;
		tr[i*2].add+=tr[i].add;
		tr[i*2+1].add+=tr[i].add;
		tr[i*2].sum+=tr[i].add*(len-len/2);
		tr[i*2+1].sum+=tr[i].add*(len/2);
		tr[i].add=0;
	}
}

void update_tree(int x,int y,int i,long long v)
{
	if(tr[i].l>=x&&tr[i].r<=y)
	{
		tr[i].add+=v;
		tr[i].sum+=v*(tr[i].r-tr[i].l+1);
		return;
	}
	push_down(i);
	int mid=(tr[i].l+tr[i].r)/2;
	if(x>mid)
		update_tree(x,y,i*2+1,v);
	else if(y<=mid)
		update_tree(x,y,i*2,v);
	else
	{
		update_tree(x,y,i*2,v);
		update_tree(x,y,i*2+1,v);
	}
	tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

long long query_tree(int x,int y,int i)
{
	if(tr[i].l>=x&&tr[i].r<=y)
		return tr[i].sum;
	push_down(i);
	int mid=(tr[i].l+tr[i].r)/2;
	if(x>mid)
		return query_tree(x,y,i*2+1);
	else if(y<=mid)
		return query_tree(x,y,i*2);
	else
		return query_tree(x,y,i*2)+query_tree(x,y,i*2+1);
	tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
}

int main()
{
	int j,ope,x,y;
	long long v;
	scanf("%d%d",&n,&m);
	for(j=1;j<=n;++j)
		scanf("%lld",a+j);
	build_tree(1,n,1);
	for(j=1;j<=m;++j)
	{
		scanf("%d%d%d",&ope,&x,&y);
		if(ope==1)
		{
			scanf("%lld",&v);
			update_tree(x,y,1,v);
		}
		else if(ope==2)
			printf("%lld\n",query_tree(x,y,1));
	}
	return 0;
}
