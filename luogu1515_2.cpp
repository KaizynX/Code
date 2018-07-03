#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int Maxn = 40;

int n, a, b;
vector<int> v {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int f[Maxn];

int main()
{
	scanf("%d%d%d", &a, &b, &n);
	for(int i = 0, tmp; i < n; ++i)
	{
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	f[0] = 1;
	for(unsigned i = 1; i < v.size(); ++i)
		for(unsigned j = 0; j < i; ++j)
			if(v[j] + a <= v[i] && v[j] + b >= v[i])
				f[i] += f[j];
	printf("%d\n", f[v.size()-1]);
	return 0;
}
