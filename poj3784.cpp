#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

int P, N, M;

typedef priority_queue<int, vector<int>, less<int> > queue_less;
typedef priority_queue<int, vector<int>, greater<int> > queue_greater;

queue_less q_l;
queue_greater q_g;

inline int getint();
// inline int abs(int tmp) { return tmp > 0 ? tmp : -tmp; }
template <typename T> inline void clear( T &now ) { T tmp; swap(tmp,now); }

int main()
{
	P = getint();
	while(P--)
	{
		int cnt = 1;
		clear(q_l); clear(q_g);
		// q_l < q_g
		N = getint(); M =getint();
		printf("%d %d\n",N,(M+1)/2);
		for(int i = 1, tmp, mid; i <= M; ++i)
		{
			tmp = getint();
			if(i == 1) // here is cnt = 1
			{
				mid = tmp;
				q_g.push(tmp);
				printf("%d ",tmp);
				continue;
			}
			// push
			if(tmp > mid) q_g.push(tmp);
			else q_l.push(tmp);
			// pop
			if(i & 1) // i % 2 == 1
			{
				int s_l = q_l.size(), s_g = q_g.size();
				while(abs(s_l - s_g) > 1)
				{
					if(s_l > s_g)
					{
						tmp = q_l.top();
						q_l.pop();
						--s_l;
						q_g.push(tmp);
						++s_g;
					}
					else
					{
						tmp = q_g.top();
						q_g.pop();
						--s_g;
						q_l.push(tmp);
						++s_l;
					}
				}
				mid = (s_l > s_g ? q_l.top() : q_g.top());
				if(++cnt >= 10) { printf("%d\n",mid); cnt = 0; }
				else printf("%d ",mid);
			}
		}
		if(cnt) putchar('\n'); // cnt != 0
	}
	return 0;
}

inline int getint()
{
	char c; bool tag = false;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = true;
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
	return tag == true ? -res : res;
}
