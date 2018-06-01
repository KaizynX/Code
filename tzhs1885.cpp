#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long 
using namespace std;
const int Maxn = 1e4+5,B=1e3,Maxl=1e4+5,W=4;
//B表示Big.d[]一个单位的大小[0,999]
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
	//从最低位开始存
	Big(int size=1):size(size)//初始化size=1,及该Big值为0
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
		for(int i=0;i<this->size;++i)//从最低位开始，有进位
		{
			tmp=this->d[i]*k;
			res.d[i]=(tmp+cnt)%B;
			cnt=(tmp+cnt)/B;
		}
		while(cnt>0)
		{
			//进位,当size 1 to 2,res.d[1++]=cnt%B
			res.d[ res.size++ ]=cnt%B;
			cnt/=B;
		}
		return res;
	}
	Big operator / (int k)//Big / int
	{
		int cnt=0;//cnt可能溢出
		Big res(this->size);
		for(int i=this->size -1;i>=0;--i)//从最高位开始除，有退位
		{
			//cnt 是高位除了余下的
			cnt=cnt*B+this->d[i];
			res.d[i]=cnt/k;
			cnt=cnt%k;
		}
		while(res.d[res.size-1]==0)//最高位为0
			res.size--;
		return res;
	}
}sum_a,ans,cnt;
//sum_a记录前面的人的左手的积
//ans记录最终答案，最大的一个
inline void in();
inline void print_Big(const Big &now);
inline void solve()
{
	sort(c+1,c+1+n);
	//计算结果
	sum_a.d[0]=c[0].a;//国王的左手，溢出不要紧，后期计算时会被自动处理掉
	for(int i=1;i<=n;++i)
	{
		cnt=sum_a/c[i].b;//计算当前大臣的奖金数
		ans=( ans<cnt ? cnt : ans );//保存最大奖金数
		sum_a=sum_a*c[i].a;//左手的和更新
	}
	print_Big(ans);//输出结果
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
		//c[0]为国王
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
