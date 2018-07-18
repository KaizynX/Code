#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int Maxw = 1e3 + 7;
const int w[] = { 1, 2, 3, 5, 10, 20};

bitset<Maxw> f;

int main()
{
	f[0] = 1;
	for(int i = 0, n; i < 6; ++i)
	{
		scanf("%d", &n);
		for(int j = 0; j < n; ++j)
			f = f | f << w[i];
	}
	printf("Total=%d\n", f.count()-1);
	return 0;
}
