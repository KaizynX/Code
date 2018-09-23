#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int n;
vector<int> v;

void solve(int rest, int last)
{
	if(!rest)
	{
		if(v.size() <= 1) return;
		printf("%d=", n);
		for(int i = 0; i < (int)v.size()-1; ++i)
			printf("%d+", v[i]);
		printf("%d\n", v.back());
		return;
	}

	for(int i = last; i <= rest; ++i)
	{
		v.push_back(i);
		solve(rest-i, i);
		v.pop_back();
	}
}

int main()
{
	scanf("%d", &n);
	solve(n, 1);
	return 0;
}
