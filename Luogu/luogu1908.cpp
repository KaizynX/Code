#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;

int n;
long long ans;
int a[Maxn], b[Maxn];

inline void read(int &);

void merge_sort(int l, int r)
{
	if(l == r) return;
	int mid = (l+r)>>1;
	merge_sort(l, mid);
	merge_sort(mid+1, r);

	int i = l, j = mid+1, k = l;
	while(k <= r)
	{
		if(j <= r && (i > mid || a[j] < a[i]))
		{
			ans += mid-i+1;
			b[k++] = a[j++];
		}
		else b[k++] = a[i++];
	}
	memcpy(a+l, b+l, sizeof(int)*(r-l+1));
}

int main()
{
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	merge_sort(1, n);
	printf("%lld\n", ans);
	return 0;
}

inline void read(int &x)
{
	char c; int tag = 1;
	while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}
