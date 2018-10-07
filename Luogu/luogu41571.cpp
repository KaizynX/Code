#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e7+7;

int n, m;
int tr[Maxn];

inline void read(int &);
void write(int);

inline void add(int i, int k)
{
	for( ; i <= n; i += i&-i) tr[i] += k;
}

inline int query(int i)
{
	int res = 0;
	for( ; i; i -= i&-i) res += tr[i];
	return res;
}

int main()
{
	read(n); read(m);
	while(m--)
	{
		int op, x, y;
		read(op); read(x);
		if(op == 0)
		{
			read(y);
			add(x, 1); add(y+1, -1);
		}
		else write(query(x)), putchar('\n');
	}
	return 0;
}

inline void read(int &x)
{
	char c;
	while(!isdigit((c=getchar())));
	x = c-'0';
	while(isdigit((c=getchar())))
		x = (x<<1)+(x<<3) + c-'0';
}

void write(int x)
{
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
