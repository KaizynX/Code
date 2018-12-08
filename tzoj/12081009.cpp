#include <bits/stdc++.h>

using namespace std;

const int Maxm = 1e5+7;

int T, L, M;

struct Node
{
	int a, b;
	bool operator < (const Node &nex) const
	{
		return a < nex.a;
	}
} tr[Maxm];

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> L >> M;
		if(!M)
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < M; ++i)
		{
			//cin >> tr[i].a >> tr[i].b;
			scanf("%d%d", &tr[i].a, &tr[i].b);
			if(tr[i].a > tr[i].b) swap(tr[i].a, tr[i].b);
		}
		sort(tr, tr+M);
		int res = tr[0].b-tr[0].a+1, last = tr[0].b;
		for(int i = 1; i < M; ++i)
		{
			if(tr[i].a > last)
				res += tr[i].b-tr[i].a+1;
			else if(tr[i].b > last)
				res += tr[i].b-last;
			last = max(last, tr[i].b);
		}
		//cout << res << endl;
		printf("%d\n", res);
	}
	return 0;
}
