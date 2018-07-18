#include<iostream>
using namespace std;
const int N=1005;
int n,k,m,ans;

struct map
{
	int sum,com[N],col,vis;
}a[N];

bool judge(int num)
{
	bool flag=1;
	int next;
	for(int i=1;i<=a[num].sum;++i)
	{
		next=a[num].com[i];
		if(a[next].col==0)continue;
		else if(a[next].col==a[num].col)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

void dfs(int num)
{
	if(num>n)
	{
		ans++;
		return;
	}
	
	for(int i=1;i<=m;++i)
	{
		a[num].col=i;
		if(judge(num))
			dfs(num+1);
		a[num].col=0;
	}
}

int main ()
{
	int x,y;
	cin>>n>>k>>m;
	for(int i=0;i<k;++i)
	{
		cin>>x>>y;
		a[x].sum++;
		a[y].sum++;
		a[x].com[a[x].sum]=y;
		a[y].com[a[y].sum]=x;
	}
	//cin AC
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
