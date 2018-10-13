#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;

int lena, lenb, f[Maxn][Maxn];
char a[Maxn], b[Maxn];

int main()
{
	scanf("%s%s", a+1, b+1);
	lena = strlen(a+1); lenb = strlen(b+1);
	for(int i = 1; i <= lena; ++i)
	{
		for(int j = 1; j <= lenb; ++j)
		{
			if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
			f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j-1]));
		}
	}
	printf("%d\n", f[lena][lenb]);
	return 0;
}
