#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 1e4 + 7;
const int Maxm = 207;

struct Node
{
	int v[Maxm];
	Node(){ memset(v, 0, sizeof v); }
} a[Maxn];

int n, m, q;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, k; i <= n; ++i)
	{
		scanf("%d", &k);
		for(int j = 0, x; j < k; ++j)
		{
			scanf("%d", &x);
			scanf("%d", &a[i].v[x]);
		}
	}

	scanf("%d", &q);
	string ope;
	while(q--)
	{
		cin >> ope;
		if(ope == "I")
		{
			int tmp;
			++n;
			scanf("%d", &tmp);
			scanf("%d", &tmp);
			for(int i = 0, tmp1, tmp2; i < tmp; ++i)
			{
				scanf("%d%d", &tmp1, &tmp2);
			}
		}
		else if(ope == "QS")
		{
			int tmp1, tmp2;
			scanf("%d%d", &tmp1, &tmp2);
		}
		else if(ope == "D")
		{
			int tmp;
			--n;
			scanf("%d", &tmp);
		}
		else if(ope == "QA")
		{
			printf("%d\n", n);
		}
	}
	puts("end");
	return 0;
}
