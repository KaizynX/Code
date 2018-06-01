#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int p[15][15],n,sum,zero[15];
//Don't know what's wrong without debug
void queue(int x,int y,int v)
{
	for(int i=0;i<n;i++)
	{
		p[x][i]+=v;
		p[i][y]+=v;
		if(x+i<n&&y+i<n)p[x+i][y+i]+=v;
		if(x+i<n&&y-i>=0)p[x+i][y-i]+=v;
		if(x-i>=0&&y+i<n)p[x-i][y+i]+=v;
		if(x-1>=0&&y-i>=0)p[x-i][y-i]+=v;
	}
	return;
}

void solve(int cur,int res[15])
{
	if(cur==n)
	{
		for(int i=0;i<n;++i)
			printf("%d ",res[i]);
		printf("\n");
		sum++;
		return;
	}
	for(int i=0;i<n;++i)
	{
		if(!p[cur][i])
		{
			cout<<cur<<" "<<i<<endl;//debug
			queue(cur,i,1);
			int now[15];
			memcpy(now,res,sizeof(res));//AC
			now[cur]=i;
			solve(cur+1,now);
			queue(cur,i,-1); 
		}
	}
	return;
}

int main()
{
	cin>>n;
	if(n<=3)
	{
		cout<<"No Solution"<<endl;
		return 0;
	}
	solve(0,zero);
	if(sum==0)cout<<"No Solution"<<endl;
	return 0;
}
/*string-----
#include <iostream>
using namespace std;
int p[15][15],n,sum;
//Don't know what's wrong without debug
void queue(int x,int y,int v)
{
	for(int i=0;i<n;i++)
	{
		p[x][i]+=v;
		p[i][y]+=v;
		if(x+i<n&&y+i<n)p[x+i][y+i]+=v;
		if(x+i<n&&y-i>=0)p[x+i][y-i]+=v;
		if(x-i>=0&&y+i<n)p[x-i][y+i]+=v;
		if(x-1>=0&&y-i>=0)p[x-i][y-i]+=v;
	}
	return;
}

void solve(int cur,string res)
{
	if(cur==n)
	{
		cout<<res<<endl;
		sum++;
		return;
	}
	for(int i=0;i<n;++i)
	{
		if(!p[cur][i])
		{
			queue(cur,i,1);
			string now=res;
			res+=(i+'0')+" ";
			solve(cur+1,now);
			queue(cur,i,-1); 
		}
	}
}

int main()
{
	string a;
	cin>>n;
	if(n<=3)
	{
		cout<<"No Solution"<<endl;
		return 0;
	}
	solve(0,a);
	if(sum==0)cout<<"No Solution"<<endl;
	return 0;
}
*/
