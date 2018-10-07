#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxm = 2e6+7;
const int Zero = 1e6;

int n;
char s[Maxm];
int f[Maxm], v[Maxm], c[Maxm];
// f[i] s-c == i max value

int main()
{
	int upv, lov;
	memset(f, -1, sizeof f);
	f[Zero] = 0;
	upv = lov = Zero;

	scanf("%d", &n);
	for(int i = 1, nums, numc; i <= n; ++i)
	{
		nums = numc = 0;
		scanf("%s", s);
		for(int j = 0, len = strlen(s); j < len; ++j)
		{
			if(s[j] == 's') nums++;
			if(s[j] == 'c') numc++;
		}
		v[i] = min(nums, numc);
		c[i] = nums-numc;
		if(c[i] == 0) f[Zero] += v[i];
		else if(c[i] > 0) upv += c[i];
		else if(c[i] < 0) lov += c[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		if(c[i] == 0) continue;
		if(c[i] > 0)
		{
			for(int j = upv; j >= lov+c[i]; --j)
			{
				if(f[j-c[i]] == -1) continue;
				if(j >= c[i]) // plus the diff
					f[j] = max(f[j], f[j-c[i]]+v[i]);
				else if(j <= 0) // minus the diff
					f[j] = max(f[j], f[j-c[i]]+v[i]+c[i]);
				else // (0, c[i])
					f[j] = max(f[j], f[j-c[i]]+v[i]+(c[i]-j));
			}
		}
		else if(c[i] < 0)
		{
			for(int j = lov; j <= upv+c[i]; ++j)
			{
				if(f[j-c[i]] == -1) continue;
				if(j <= c[i]) // plus the diff
					f[j] = max(f[j], f[j-c[i]]+v[i]);
				else if(j >= 0) // minus the diff
					f[j] = max(f[j], f[j-c[i]]+v[i]+(-c[i]));
				else // (c[i], 0)
					f[j] = max(f[j], f[j-c[i]]+v[i]+(j-c[i]));
			}
		}
	}
	printf("%d\n", f[Zero]);
	return 0;
}
