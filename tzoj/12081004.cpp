#include <bits/stdc++.h>

using namespace std;

int n, m;
int p, d;

int main()
{
	while(cin >> n >> m)
	{
		int maxl, minl;
		cin >> p >> d;
		if(d == 1) maxl = minl = m+1-p;
		else maxl = minl = p;
		for(int i = 1; i < n; ++i)
		{
			cin >> p >> d;
			if(d == 1)
			{
				maxl = max(maxl, m+1-p);
				minl = min(minl, m+1-p);
			}
			else
			{
				maxl = max(maxl, p);
				minl = min(minl, p);
			}
		}
		cout << minl << " " << maxl << endl;
	}
	return 0;
}
