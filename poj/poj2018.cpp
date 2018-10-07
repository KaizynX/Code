#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;
const long long INF = 2e11;

int n, f, ans;
int mina, maxa;
int a[Maxn];
long long s[Maxn];

int main()
{
	while(scanf("%d%d",&n,&f) != EOF)
	{
		mina = 2000000; maxa = 1;
		for(int i = 1; i <= n; ++i) // 1 <= a[i] <= 2000
		{
			scanf("%d",a+i);
			a[i] *= 1000;
			if(a[i] < mina) mina = a[i];
			if(a[i] > maxa) maxa = a[i];
		}
		ans = mina; // if l == r
		for(int l = mina, r = maxa, mid; l < r; ans = l)
		{
			long long mins = INF, maxv = -INF;
			mid = (l + r + 1) >> 1; // take the big one
			// memset(s,0,sizeof s);
			for(int i = 1; i <= n; ++i) s[i] = s[i-1] + (a[i] - mid);
			for(int i = f; i <= n; ++i)
			{
				// operator [i-f+1,i] , add i-f
				if(s[i-f] < mins) mins = s[i-f];
				if(s[i] - mins > maxv) maxv = s[i] - mins;
			}
			// if(maxv == 0) { ans = mid; break;}
			if(maxv >= 0) l = mid; // could get the ans == mid
			else r = mid - 1; // can't get it , delete it
		}
		printf("%d\n",ans);
	}
	return 0;
}
