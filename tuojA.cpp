#include <cstdio>
#include <iostream>

using namespace std;

int s,p,n;

int main()
{
	int i,m,now;
	char c;
	while(scanf("%d%d%d",&s,&p,&n)!=EOF)
	{
		now=s;
		for(i=1;i<=n;++i)
		{
			cin>>c;
			scanf("%d",&m);
			if(c=='x')
			{
				if(now+m<=p)
					now+=m;
			}
			else if(c=='y')
			{
				if(now-m>=0)
					now-=m;
			}
		}
		printf("%d\n",now);
	}
	return 0;
}
