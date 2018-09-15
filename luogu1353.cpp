#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;

int n, m, a;
map<int, int> mmp[Maxn];
// mmp[i][d] in i'th minite with d tired

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		mmp[i].insert(make_pair(0, 0));
	for(int i = 1, s, d; i < n; ++i)
	{
		scanf("%d", &a);
		for(map<int, int>::iterator it = mmp[i].begin(); it != mmp[i].end(); ++it)
		{
			d = it->first;
			s = it->second;
			// run
			if(mmp[i+1].count(d+1))
				mmp[i+1][d+1] = max(mmp[i+1][d+1], s+a);
			else mmp[i+1].insert(make_pair(d+1, s+a));
			// start to rest
			if(!d || i+d > n) continue;
			mmp[i+d][0] = max(mmp[i+d][0], s);
		}
	}
	scanf("%d", &a); // last minite is uesless
	printf("%d\n", mmp[n][0]);
	return 0;
}
