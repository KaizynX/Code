#include <cstring>
#include <cstdio>
int n,max=0;
char ch1[11010],ch[110101],a[10010];
char zhaox(int i)
{
	int j;
	for(j=n;j>=1;j--)
	   if(a[j]!='w')
	     return a[j];
	return a[1];
}
char zhaoy(int i)
{
	int j;
	for(j=1;j<=n;j++)
	   if(a[j]!='w')
	     return a[j];
	return a[n];
}
int main()
{
	int i,j,sum;
	char x,y;
	scanf("%d",&n);
	scanf("%s",ch1);
	for(i=1;i<=n;i++)
	   ch[i]=ch1[i-1];
	for(i=28;i<=n-1;i++)
	{
		memset(a,0,sizeof(a));
		for(j=i+1;j<=n;j++)
		   a[j-i]=ch[j];
		for(j=1;j<=i;j++)
			a[j+n-i]=ch[j];
		x=zhaox(i);
		y=zhaoy(i+1);
		sum=0;
		for(j=n;j>=1;j--)
			if(a[j]==x || a[j]=='w')
			   sum++;
			else break;
		for(j=1;j<=n;j++)
		  if(a[j]==y || a[j]=='w')
			   sum++;
			else break;
		if(sum>max)
		   max=sum;
	}
	printf("%d",max);
	return 0;
}
