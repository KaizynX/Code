#include <cstdio>
#include <cstring>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 1e3+7;
const int INF = 0x3f3f3f3f;

string str;
int f[Maxn][Maxn], ans = INF, len;

int main()
{
	cin >> str;
	len = str.length();
	memset(f, 0x3f, sizeof f);
	f[1][len] = str[0] == str[len-1] ? 0 : 1;
	for(int i = 1; i <= len; ++i)
	{
		for(int j = len; j >= i; --j)
		{
			f[i][j] = min(f[i][j], f[i][j+1]+1); // insert str[j] after i
			f[i][j] = min(f[i][j], f[i-1][j]+1); // insert str[i] before j
			if(str[i-1] == str[j-1]) f[i][j] = min(f[i][j], f[i-1][j+1]);
			if(i == j) ans = min(ans, f[i][j]);
#ifdef DEBUG
			printf("%d %d %d\n", i, j, f[i][j]);
#endif
		}
	}
	printf("%d\n", ans);
	return 0;
}
