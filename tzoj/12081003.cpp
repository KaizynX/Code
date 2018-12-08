#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int a;

int main()
{
	while(scanf("%d", &a) != EOF)
	{
		printf("%.1f\n", (double)4*a*a*a/PI);
	}
	return 0;
}
