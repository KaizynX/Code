#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

const int Maxn = 5000+5;

int n,k,ans;
map <int,bool> m;
map <int,bool> :: iterator it;

int main()
{
	int a;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		it = m.find(a);
		if(it == m.end() )
		{
			//m[a]=1;
			m.insert( pair<int ,bool>(a,1) );
			ans++;
		}
	}
	if(n-k<ans)ans=n-k;
	printf("%d",ans);
	return 0;
}
