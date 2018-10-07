#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;
const int Maxm = 4e4+7;

int n, W;
int b[Maxm];
vector<int> v, w;

int main()
{
	scanf("%d%d", &n, &W);
	for(int i = 1, cnt, vi, wi, m; i <= n; ++i)
	{
		scanf("%d%d%d", &vi, &wi, &m);
		cnt = 1;
		while(m-cnt > 0)
		{
			m -= cnt;
			v.push_back(vi*cnt);
			w.push_back(wi*cnt);
			cnt <<= 1;
		}
		v.push_back(vi*m);
		w.push_back(wi*m);
	}
	for(int i = 0; i < w.size(); ++i)
		for(int j = W; j >= w[i]; --j)
			b[j] = max(b[j], b[j-w[i]]+v[i]);
	printf("%d\n", b[W]);
	return 0;
}
