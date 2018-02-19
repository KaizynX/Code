#include <iostream>
using namespace std;
const int N=305;
int n,p,ans=1;

struct node
{
	bool used;
	int son[N],num,sum;//add son from 1
}a[N];

int search(int n)//AC
{
	int minn=-1,flag,next;
	for(int i=1;i<=a[n].num;++i)
	{
		next=a[n].son[i];
		if(a[next].num>minn)
		{
			minn=a[next].num;
			flag=next;
		}
		else if(a[next].num==minn)
		{
			if(a[next].sum>a[flag].sum)
				flag=next;
		}
	}
	return flag;
}

void solve(int n)
{
	if(a[n].num<2)return;
	int flag,next;
	flag=search(n);
	ans+=a[n].num-1;
	for(int i=1;i<=a[n].num;++i)
	{
		next=a[n].son[i];
		if(next==flag)continue;
		solve(next);
	}
}

void addson(int n)//AC
{
	int res=0,next;
	for(int i=1;i<=a[n].num;++i)
	{
		next=a[n].son[i];
		addson(next);
		res+=a[next].sum;
	}
	a[n].sum+=res;
}

int main()
{
	int i,j,f,s;
	cin>>n>>p;
	a[1].used=1;
	for(int k=0;k<p;++k)
	{
		cin>>i>>j;
		if(a[i].used)f=i,s=j;
		else if(a[j].used)f=j,s=i;
		a[s].used=1;
		a[f].num++;
		a[f].son[a[f].num]=s;
	}
	//cin AC
	for(int k=1;k<=n;++k)
		a[k].sum=1;
	addson(1);
	solve(1);
	cout<<ans<<endl;
	return 0;
}
