#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 1000000+5;

int n,m,ans=Maxn,npos;//npos=0
int r[Maxn],d[Maxn],s[Maxn],t[Maxn];
int a[Maxn];//ǰ׺��

int getint();//���
inline void in();
bool check(int pos)
{
	int nowr=0;
	//ǰ׺���޸�
	// a[start]+=d  a[tail+1]-=d
	if(pos>npos)//����
	{
		for(int i=npos+1;i<=pos;++i)
		{
			a[ s[i] ]+=d[i];
			a[ t[i]+1 ]-=d[i];
		}
	}
	else if(pos<npos)//��ȥ
	{
		for(int i=pos+1;i<=npos;++i)
		{
			a[ s[i] ]-=d[i];
			a[ t[i]+1 ]+=d[i];
		}
	}
	npos=pos;//����
	//ǰ׺��Ӧ��
	//ģ�����֪
	for(int i=1;i<=n;++i)
	{
		nowr+=a[i];
		if(nowr>r[i])//��ǰλ���޷�����
			return 1;
	}
	return 0;
}

inline void solve()
{
	int l=1,r=m,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))//��ǰ�޷�����
		{
			ans=min(ans,mid);
			r=mid-1;//��ǰ���
		}
		else 
		{
			l=mid+1;
		}
	}
	if(ans==Maxn)printf("0\n");
	else 
	{
		printf("-1\n%d",ans);
	}
}

int main()
{
	in();
	solve();
	return 0;
}

inline void in()
{
	n=getint();
	m=getint();
	for(int i=1;i<=n;++i)
	{
		r[i]=getint();
	}
	for(int i=1;i<=m;++i)
	{
		d[i]=getint();
		s[i]=getint();
		t[i]=getint();
	}
}

int getint()
{
	int res=0;
	char c=getchar();
	while(c<'0' || c>'9')
		c=getchar();
	while(c>='0' && c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
