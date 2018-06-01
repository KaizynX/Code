#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int Maxn = 100000;

int n,m;
int dir[Maxn+5];//0³¯Àï 1³¯Íâ
string name[Maxn+5];

inline void in();
inline void solve()
{
	int a,s,now=0;//0×ó 1ÓÒ
	for(int i=0;i<m;++i)
	{
		scanf("%d%d",&a,&s);
		if(dir[now]==0&&a==1 || dir[now]==1&&a==0)
			now=(now+s)%n;
		else 
		{
			//now=(now-s)%n;
			now=(now+n-s%n)%n;
		}
	}
	cout<<name[now]<<endl;
}

int main()
{
	in();
	solve();
	return 0;
}

inline void in()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%d",dir+i);
		cin>>name[i];
	}
}
