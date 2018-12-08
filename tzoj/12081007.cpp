#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 1e2+7;
const int Maxt = 50;

int n, E1, E2, E3, t, h;
long long val[Maxt];

int main()
{
	while(cin >> n && n)
	{
		memset(val, 0, sizeof val);
		cin >> E1 >> E2 >> E3;
		for(int i = 0; i < n; ++i)
		{
			cin >> t >> h;
			int num = t/25;
			// 第i点j深度
			for(int j = 1; j <= h; ++j)
			{
				// 时间=移动*2次+开采*2
				// 电力=传送*2+移动*2+开采
				val[j*2+num*2] += t-num*E2*2-num*j*2-num;
			}
		}
		// 启动
		long long ans = -E1, cur = -E1;
		// 维持
		for(int i = 1; i <= 40; ++i)
		{
#ifdef DEBUG
			printf("[%d]=%I64d\n", i, val[i]);
#endif
			cur += val[i]-E3;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}
