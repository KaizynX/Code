#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 107;

int n;
double mark[Maxn], dollar[Maxn];

int main()
{
	double excg;
	scanf("%d", &n);
	dollar[0] = 100.0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lf", &excg);
		excg /= 100.0;
		for(int j = 0; j < i; ++j)
		{
			mark[i] = max(mark[i], dollar[j] * excg);
			dollar[i] = max(dollar[i], mark[j] / excg);
		}
	}
	printf("%.2f\n", max(dollar[n], mark[n] / excg));
	return 0;
}
