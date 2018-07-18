#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int Maxn = 1e2+5;
const int Maxp = 1e4+5;

int n,p;
//邻接表
int u[Maxp],v[Maxp],w[Maxp],fir[Maxp],nex[Maxp];
bool in_q[Maxn];

struct P
{
	int C,U;
}a[Maxn];

queue <int> q,ans;
vector <int> res;

inline void clear(queue<int> &q)
{
	queue<int> empty;
	swap(empty,q);
}

int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].C,&a[i].U);
		if(a[i].C)
		{
			q.push(i);
		}
	}
	for(int i=1;i<=p;++i)
	{
		scanf("%d%d%d",u+i,v+i,w+i);
		nex[i] = fir[ u[i] ];
		fir[ u[i] ] = i;
	}
	//bfs
	while(!q.empty())//空了表示最后一次出了
	{
		clear(ans);//没结束,清空上次缓存的答案
		unsigned size=q.size();
		for(unsigned i=0;i<size;++i)
		{
			int tmp=q.front();
			q.pop();
			in_q[ tmp ] = false;
			if(a[tmp].C<=0)continue;//C>0才是兴奋状态
			ans.push(tmp);//缓存答案
			for(int k=fir[tmp];k;k=nex[k])
			{
				// W*C累加
				a[ v[k] ].C += w[k]*a[ tmp ].C;
				// 入队列
				if(!in_q[ v[k] ])
				{
					q.push(v[k]);
					in_q[ v[k] ] = true;
					// 减去U
					a[ v[k] ].C -= a[ v[k] ].U;
				}
			}
		}
	}
	//输出答案
	while(!ans.empty())
	{
		res.push_back(ans.front());
		ans.pop();
	}
	//按编号由小到大输出
	sort(res.begin(),res.end());
	//判断输出层最后状态是否都为0
	bool flag_out=false;//判断是否输出NULL
	vector<int>::iterator it;
	for(it=res.begin();it!=res.end();++it)
	{
		if(a[*it].C>0)
		{
			flag_out=true;
			break;
		}
	}
	if(!flag_out)
	{
		printf("NULL\n");
		return 0;
	}
	for(it=res.begin();it!=res.end();++it)
	{
		if(a[*it].C>0)//仅输出最后状态大于零的输出层神经元状态
			printf("%d %d\n",*it,a[*it].C);
	}
	return 0;
}
