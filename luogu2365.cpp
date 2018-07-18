#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 5e5 + 7;

int n, s;
int ti[Maxn], fi[Maxn];
int f[Maxn][2], t[Maxn][2], v[Maxn][2];
// 0 ==> follow last group
// 1 ==> new group
// f ==> fee
// t ==> the end time
// v ==> fi of last group

int main()
{
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i) scanf("%d%d", ti+i, fi+i);
	t[0][0] = t[0][1] = s;
	for(int i = 1, tmp; i <= n; ++i)
	{
		f[i][0] = f[i-1][0] + t[i-1][0]*fi[i] + v[i-1][0]*ti[i] + ti[i]*fi[i];
		tmp = f[i-1][1] + t[i-1][1]*fi[i] + v[i-1][1]*ti[i] + ti[i]*fi[i];
		if(f[i][0] < tmp)
		{
			t[i][0] = t[i-1][0] + ti[i];
			v[i][0] = v[i-1][0] + fi[i];
		}
		else
		{
			f[i][0] = tmp;
			t[i][0] = t[i-1][1] + ti[i];
			v[i][0] = v[i-1][1] + fi[i];
		}

		f[i][1] = f[i-1][0] + (t[i-1][0]+s+ti[i])*fi[i];
		tmp = f[i-1][1] + (t[i-1][1]+s+ti[i])*fi[i];
		if(f[i][1] < tmp)
		{
			t[i][1] = t[i-1][0] + s + ti[i];
			v[i][0] = fi[i];
		}
		else
		{
			f[i][1] = tmp;
			t[i][1] = t[i-1][1] + s + ti[i];
			v[i][1] = fi[i];
		}
	}
	printf("%d\n",min(f[n][0], f[n][1]));
	return 0;
}
