#include <cstdio>
#include <iostream>

using namespace std;

int A, B;
long long ans;

inline long long sum(int l, int r)
{
	if(l > r) return 0;
	return (long long)(l+r)*(r-l+1)/2;
}

int main()
{
	scanf("%d%d", &A, &B);
	for(int i = 1, tag; i <= B; ++i)
	{
		if(i > A) A = i;
		tag = i&1 ? -1 : 1;
		int c1 = A/i, c2 = B/i;
		if(c1 == c2) ans += tag*c1*(B-A+1);
		else
		{
			int n1 = i*(c1+1)-A,
				n2 = B-i*c2+1;
			ans += tag*(n1*c1+n2*c2+i*sum(c1+1, c2-1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
