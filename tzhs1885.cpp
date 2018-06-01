#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long 
using namespace std;
const int Maxn = 1e4+5,B=1e3,Maxl=1e4+5,W=4;
//B��ʾBig.d[]һ����λ�Ĵ�С[0,999]
int n;
struct C
{
	int a,b,ab;
	bool operator < (const C &another)const
	{
		return this->ab < another.ab;
	}
}c[Maxn];

struct Big
{
	int size,d[Maxl];
	//�����λ��ʼ��
	Big(int size=1):size(size)//��ʼ��size=1,����BigֵΪ0
	{
		size=1;
		memset(d,0,sizeof d);
	}
	bool operator < (const Big &another)const
	{
		if(this->size > another.size)return 0;
		else if(this->size < another.size)return 1;
		for(int i=this->size -1;i>=0;--i)
		{
			if(this->d[i] < another.d[i])return 1;
		}
		return 0;
	}
	Big operator * (int k)//Big * int
	{
		int cnt=0,tmp=0;
		Big res(this->size);
		for(int i=0;i<this->size;++i)//�����λ��ʼ���н�λ
		{
			tmp=this->d[i]*k;
			res.d[i]=(tmp+cnt)%B;
			cnt=(tmp+cnt)/B;
		}
		while(cnt>0)
		{
			//��λ,��size 1 to 2,res.d[1++]=cnt%B
			res.d[ res.size++ ]=cnt%B;
			cnt/=B;
		}
		return res;
	}
	Big operator / (int k)//Big / int
	{
		int cnt=0;//cnt�������
		Big res(this->size);
		for(int i=this->size -1;i>=0;--i)//�����λ��ʼ��������λ
		{
			//cnt �Ǹ�λ�������µ�
			cnt=cnt*B+this->d[i];
			res.d[i]=cnt/k;
			cnt=cnt%k;
		}
		while(res.d[res.size-1]==0)//���λΪ0
			res.size--;
		return res;
	}
}sum_a,ans,cnt;
//sum_a��¼ǰ����˵����ֵĻ�
//ans��¼���մ𰸣�����һ��
inline void in();
inline void print_Big(const Big &now);
inline void solve()
{
	sort(c+1,c+1+n);
	//������
	sum_a.d[0]=c[0].a;//���������֣������Ҫ�������ڼ���ʱ�ᱻ�Զ������
	for(int i=1;i<=n;++i)
	{
		cnt=sum_a/c[i].b;//���㵱ǰ�󳼵Ľ�����
		ans=( ans<cnt ? cnt : ans );//������󽱽���
		sum_a=sum_a*c[i].a;//���ֵĺ͸���
	}
	print_Big(ans);//������
}

int main()
{
	in();
	solve();
	return 0;
}

inline void in()
{
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
	{
		//c[0]Ϊ����
		scanf("%d%d",&c[i].a,&c[i].b);
		c[i].ab=c[i].a*c[i].b;
	}
}

inline void print_Big(const Big &now)
{
	printf("%d",now.d[ now.size-1 ]);
	for(int i=now.size-2;i>=0;--i)
	{
		printf("%03d",now.d[i]);
	}
	putchar('\n');
}
