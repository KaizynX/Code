#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=1;i<=7;++i)
	{
		printf("10.%d: AC %d\n",i,x);
		x+=y;
	}
	return 0;
}
