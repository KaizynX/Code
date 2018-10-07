#include <bits/stdc++.h>

using namespace std;

const int Maxn = 11000003;

char s[Maxn], ss[Maxn<<1];
int p[Maxn<<1];

inline int Manacher()
{
	int res = 0, id = 0, mx = 0, len = 1;
	ss[0] = ss[1] = '#';
	for(int i = 0, sl = strlen(s); i < sl; ++i)
	{
		ss[++len] = s[i];
		ss[++len] = '#';
	}
	for(int i = 1; i < len; ++i)
	{
		if(i < mx) p[i] = min(p[id*2-i], mx-i);
		else p[i] = 1;
		while(ss[i+p[i]] == ss[i-p[i]]) p[i]++;
		if(mx < i+p[i])
		{
			id = i;
			mx = i+p[i];
		}
		res = max(p[i]-1, res);
	}
	return res;
}

int main()
{
	scanf("%s", s);
	printf("%d\n", Manacher());
	return 0;
}
