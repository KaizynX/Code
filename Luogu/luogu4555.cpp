#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;

char a[Maxn], b[Maxn<<1];
int len, ans;
int p[Maxn<<1], l[Maxn<<1], r[Maxn];

inline void Manacher(char *str)
{
	len = strlen(str+1);
	b[0] = b[1] = '#';
	for(int i = 1; i <= len; ++i)
		b[i<<1] = str[i], b[i<<1|1] = '#';
	len = len<<1|1;
	int id, mx = 0;
	for(int i = 1; i <= len; ++i)
	{
		if(i < mx) p[i] = min(p[id*2-i], mx-i);
		else p[i] = 1;
		while(b[i-p[i]] == b[i+p[i]]) p[i]++;
		if(mx < i+p[i]) id = i, mx = i+p[i];
	}
}

int main()
{
	gets(a+1);
	Manacher(a);
	int now = 1;
	for(int i = 1; i <= len; ++i)
		while(now <= i+p[i]-1)
			l[now++] = i;
	now = len;
	for(int i = len; i; --i)
		while(now >= i-p[i]+1)
			r[now--] = i;
	for(int i = 1; i <= len; ++i)
		ans = max(ans, r[i]-l[i]);
	printf("%d\n", ans);
	return 0;
}
