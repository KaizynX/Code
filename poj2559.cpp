#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n;
int s_top; // [0,s_top)
int w[Maxn];
long long s[Maxn]; // stack
long long ans;
inline int getint();

int main()
{
	int width;
	while((n = getint()))
	{
		ans = 0;
		// s_top = 0; // clear the stack
		for(int i = 0, cur; i < n; ++i)
		{
			cur = getint();
			width = 0;
			while(s_top && s[s_top-1] > cur)
			{
				width += w[s_top-1];
				ans = max(ans, s[s_top-1] * width);
				--s_top;
			}
			// push
			s[s_top] = cur;
			w[s_top] = width + 1;
			++s_top;
		}
		width = 0;
		while(s_top)
		{
			width += w[s_top-1];
			ans = max(ans, s[s_top-1] * width);
			--s_top;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res;
}
