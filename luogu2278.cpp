#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct process
{
	int num, start, time, level;
	
	process (int a = 0, int b = 0, int c =0, int d = 0) :
		num(a), start(b), time(c), level(d) { }

	bool operator < (const process &b) const
	{
		if(level == b.level) return start > b.start;
		return level < b.level;
	}
} tmp;

priority_queue <process> q;

int main()
{
	int a,b,c,d;
	int cur = 0;

	while(scanf("%d%d%d%d",&a,&b,&c,&d) == 4)
	{
		// operate
		while(!q.empty())
		{
			tmp = q.top();
			q.pop();
			// tmp.start <= b
			if(tmp.time <= b - cur) // can finish it
			{
				cur += tmp.time;
				printf("%d %d\n",tmp.num,cur);
			}
			else // can't
			{
				tmp.time -= b - cur;
				q.push(tmp);
				break;
			}
		}
		// push it in
		q.push(process(a,b,c,d));
		//  cur < b || q.empty()
		cur = b;
	}

	while(!q.empty())
	{
		tmp = q.top();
		q.pop();
		cur += tmp.time;
		printf("%d %d\n",tmp.num,cur);
	}
	return 0;
}

