#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > h;

inline void read(int &x)
{
	char c; int tag = 1;
	while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

inline void write(int x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}

int main()
{
	read(n);
	for(int i = 1, op, x; i <= n; ++i)
	{
		read(op);
		if(op == 1) read(x), h.push(x);
		else if(op == 2) write(h.top()), putchar('\n');
		else h.pop();
	}
	return 0;
}
