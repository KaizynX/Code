#include <iostream>
#include <cstdio>
#include <vector>
#define DEBUG

using namespace std;

const int Maxt = 1007;
const int Maxw = 40;

int T, W;
vector <int> v;
int f[Maxw];

int main()
{
	scanf("%d%d", &T, &W);
	for(int i = 1, last = 0, now, cnt = 0; i <= T; ++i)
	{
		scanf("%d", &now);
		if(now == last) ++cnt;
		else// the first one is uesless
		{
			v.push_back(cnt);
			last = now;
			cnt = 1;
		}
		// the last one
		if(i == T && now == last) v.push_back(cnt);
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
#ifdef DEBUG
		printf("%d ", *it);
#endif
		for(int w = W+1; w > 0; --w)
			f[w] = max(f[w], f[w-1] + *it);
	}
#ifdef DEBUG
	putchar('\n'); putchar('\n');
	for(int i = 1; i <= W; ++i)
		printf("%d ", f[i]);
	putchar('\n'); putchar('\n');
#endif
	printf("%d\n", f[W+1]);
	return 0;
}
