#include <bits/stdc++.h>

using namespace std;

int n, a;

int main()
{
	while(cin >>n)
	{
		map<int, int> mmp;
		int res = 0, cur = 0;
		for(int i = 1; i <= n*2; ++i)
		{
			cin >> a;
			if(mmp[a] > 0) mmp[a]--, cur--;
			else mmp[a]++, res = max(res, ++cur);
		}
		cout << res << endl;
	}
	return 0;
}
