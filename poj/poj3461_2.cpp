#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 1e6+7;
const int BASE = 131;

char a[Maxn], b[Maxn];
int len_a, len_b, ans, T;
unsigned long long _hash[Maxn], pattern, base;

int main()
{
    scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		base = 1;
		pattern = 0;
		scanf("%s", a);
        scanf("%s", b);
		len_a = strlen(a);
		len_b = strlen(b);
		// base = BASE^len_a
		for(int i = 0; i < len_a; ++i)
			base *= BASE;
		for(int i = len_a-1; i >= 0; --i)
			pattern = pattern*BASE + a[i];
		for(int i = len_b-1; i >= 0; --i)
			_hash[i] = _hash[i+1]*BASE + b[i];
		for(int i = 0; i <= len_b - len_a; ++i)
			if(pattern == _hash[i] - _hash[i+len_a]*base)
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}
