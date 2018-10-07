#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int n, T, ans;

int main()
{
	cin >> n >> T;
	for(int i = 1, c, t; i <= n; ++i)
	{
		cin >> c >> t;
		if(t > T) continue;
		if(!ans) ans = c;
		else ans = min(ans, c);
	}
	if(!ans) cout <<"TLE" << endl;
	else cout << ans << endl;
	return 0;
}
