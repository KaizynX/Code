#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5005;
const int maxm=200005;
int n,m,f[maxn],road;
long long ans;
struct tree
{
	int x,y,z;
}t[maxm];
bool cmp(tree a,tree b)
{
	return a.z<b.z;
}
int ff(int son)
{
	int fa=son;
	if(son!=f[son])
		fa=ff(f[son]);
	f[son]=fa;
	return fa;
}
int main()
{
	int i,x,y,z,fx,fy;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		f[i]=i;
	for(i=0;i<m;++i)
		cin>>t[i].x>>t[i].y>>t[i].z;
	sort(t,t+m,cmp);
	for(i=0;i<m;++i)
	{
		fx=ff(t[i].x);
		fy=ff(t[i].y);
		if(fx!=fy)
		{
			f[fx]=fy;
			ans+=t[i].z;
			road++;
		}
		if(road==n-1)
			break;
	}
	if(road==n-1)
		cout<<ans<<endl;
	else
		cout<<"orz"<<endl;
	return 0;
}
