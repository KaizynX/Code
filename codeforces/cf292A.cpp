#include <bits/stdc++.h>

using namespace std;

int n, t, c;
int T, S;

int main()
{
	cin >> n;
	for(int i = 1, last, now; i <= n; ++i)
	{
		cin >> t >> c;
		if(i == 1)
		{
			last = t;
			T = t+c;
			S = now = c;
		}
		else
		{
			S = max(S, (now += c-min(now, t-last)));
			T = max(T, t)+c;
			last = t;
		}
	}
	cout << T << " " << S << endl;
	return 0;
}
