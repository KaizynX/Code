#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int n,m,k,ans;
map <string,int> t;
map <string,int> :: iterator it;

int main()
{
	int i,score;
	string name;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;++i)
	{
		cin>>name>>score;
		t.insert( pair<string,int> (name,score));
	}
	for(i=1;i<=m;++i)
	{
		cin>>name>>score;
		t.insert( pair<string,int> (name,-score));
	}
	for(i=1;i<=k;++i)
	{
		cin>>name;
		it=t.find(name);
		if(it!=t.end())
			ans+=t[name];
	}
	printf("%d\n",ans);
	return 0;
}
