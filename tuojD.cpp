#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int Maxn = 100+5;

inline bool cmp(double a,double b)
{
	int inta=a*100;
	int intb=b*100;
	return inta == intb;
}

int n;
struct singer
{
	string num,name;
	double score;
	bool operator < (const singer &b)const
	{
		if(cmp(score,b.score))
			return num<b.num;
		return score > b.score;
	}
}a[Maxn];

int main()
{
	int now,sum,maxs,mins;
	int lasti=0,nowi=0;
	double lasts=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		mins=100;
		maxs=0;
		sum=0;
		cin>>a[i].num>>a[i].name;
		for(int j=1;j<=10;++j)
		{
			scanf("%d",&now);
			mins=min(mins,now);
			maxs=max(maxs,now);
			sum+=now;
		}
		a[i].score=(sum-mins-maxs)/8;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		if(!cmp(lasts,a[i].score))
			nowi++;
		cout<<nowi<<" "<<a[i].num<<" "<<a[i].name<<" ";
		printf("%.2f\n",a[i].score);
		lasts=a[i].score;
	}
	return 0;
}
