#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;

int main()
{
	int n,i,ope,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&ope);
		if(ope==1)
		{
			scanf("%d",&a);
			q.push(a);
		}
		else if(ope==2)
			printf("%d\n",q.top());
		else if(ope==3)
			q.pop();
	}
	return 0;
}
