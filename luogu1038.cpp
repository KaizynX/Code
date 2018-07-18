#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int Maxn = 1e2+5;
const int Maxp = 1e4+5;

int n,p;
//�ڽӱ�
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
	while(!q.empty())//���˱�ʾ���һ�γ���
	{
		clear(ans);//û����,����ϴλ���Ĵ�
		unsigned size=q.size();
		for(unsigned i=0;i<size;++i)
		{
			int tmp=q.front();
			q.pop();
			in_q[ tmp ] = false;
			if(a[tmp].C<=0)continue;//C>0�����˷�״̬
			ans.push(tmp);//�����
			for(int k=fir[tmp];k;k=nex[k])
			{
				// W*C�ۼ�
				a[ v[k] ].C += w[k]*a[ tmp ].C;
				// �����
				if(!in_q[ v[k] ])
				{
					q.push(v[k]);
					in_q[ v[k] ] = true;
					// ��ȥU
					a[ v[k] ].C -= a[ v[k] ].U;
				}
			}
		}
	}
	//�����
	while(!ans.empty())
	{
		res.push_back(ans.front());
		ans.pop();
	}
	//�������С�������
	sort(res.begin(),res.end());
	//�ж���������״̬�Ƿ�Ϊ0
	bool flag_out=false;//�ж��Ƿ����NULL
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
		if(a[*it].C>0)//��������״̬��������������Ԫ״̬
			printf("%d %d\n",*it,a[*it].C);
	}
	return 0;
}
