#include <iostream>
#include <cstdio>
#include <cstring>

#define DEBUG

using namespace std;

const int Maxn = 5e5 + 7;

int n;
long long ans;
int a[Maxn], tmp[Maxn];

void merge_sort(int l, int r) // [L, R)
{
	if(r - l <= 1) return;
	int mid = (l + r) >> 1;
	merge_sort(l,mid); // [L, Mid)
	merge_sort(mid,r); // [Mid, R)

	int i = l, j = mid, pos = l;
	while(pos < r)
	{
		if(i >= mid || j < r && a[j] < a[i] )
		{
			tmp[pos++] = a[j++];
			ans += mid - i;
		}
		else tmp[pos++] = a[i++];
	}
	memcpy(a+l,tmp+l,sizeof(int)*(r-l));
	// for(int k = l; k < r; ++k) a[k] = tmp[k];
}

int main()
{
	while( scanf("%d",&n) && n !=0 )
	{
		for(register int i = 0; i < n; ++ i) scanf("%d",a+i);
		ans = 0;
		merge_sort(0,n);
#ifdef DEBUG
		for(int i = 0; i < n; ++ i) printf("%d ",a[i]);
		putchar('\n');
#endif
		printf("%lld\n",ans);
	}
	return 0;
}
