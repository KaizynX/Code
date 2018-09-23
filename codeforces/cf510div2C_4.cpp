#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;
const int INF = 1e9+7;

int n, nega = -INF, negid, cnt, negn;
int a[Maxn];
vector<int> v, z;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		if(a[i] == 0) z.push_back(i);
		if(a[i] < 0)
		{
			negn++;
			if(a[i] > nega)
			{
				nega = a[i];
				negid = i;
			}
		}
	}
	for(int i = 0; i < (int)z.size()-1; ++i)
	{
		printf("1 %d %d\n", z[i], z[i+1]);
		cnt++;
	}

	int pos = -1;
	if(z.size()) pos = z.back();
	if(negn&1)
	{
		if(z.size())
		{
			printf("1 %d %d\n", pos, negid);
			cnt++;
		}
		pos = negid;
	}
	if(cnt == n-1) return 0;
	else if(pos != -1) printf("2 %d\n", pos);

	for(int i = 1; i <= n; ++i)
		if(a[i] != 0 && (negn%2 == 0 || i != negid))
			v.push_back(i);
	for(int i = 0; i < (int)v.size()-1; ++i)
		printf("1 %d %d\n", v[i], v[i+1]);
	return 0;
}
