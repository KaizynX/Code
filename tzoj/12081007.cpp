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
			// ��i��j���
			for(int j = 1; j <= h; ++j)
			{
				// ʱ��=�ƶ�*2��+����*2
				// ����=����*2+�ƶ�*2+����
				val[j*2+num*2] += t-num*E2*2-num*j*2-num;
			}
		}
		// ����
		long long ans = -E1, cur = -E1;
		// ά��
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
