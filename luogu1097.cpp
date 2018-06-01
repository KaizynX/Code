#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int n;
map <int,int> m;
set <int> s;

int main()
{
	int cnt;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&cnt);
		if(m.find(cnt)!=m.end())
		{
			m[cnt]++;
		}
		else
		{
			m.insert(make_pair(cnt,1));
			s.insert(cnt);
		}
	}
	//set<int>::iterator it;
	for(auto it=s.begin();it!=s.end();++it)
	{
		printf("%d %d\n",*it,m[*it]);
	}
	return 0;
}
