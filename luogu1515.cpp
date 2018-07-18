#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxn = 40;

int n, a, b;
int h[Maxn] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int f[Maxn];

int main()
{
	cin >> a >> b >> n;
	for(int i = 14; i <= 13 + n; ++i)
		cin >> h[i];
	sort(h, h+n+14);
	f[0] = 1;
	for(int i = 0; i < 13 + n; ++i)
	{
		int mins = h[i] + a, maxs = h[i] + b;
		int head, tail = upper_bound(h, h+n+14, maxs) - h; // h[tail] > maxs
		for(int j = 0; j <= 13 + n; ++j)
			if(h[j] >= mins)
			{
				head = j; break;
			}
		--head;

		for(int j = head + 1; j < tail; ++j)
			f[j] += f[i];
#ifdef DEBUG
		cout << mins << " " << maxs << " ";
		cout << head << " " << tail << endl;
		for(int j = 0; j <= 13+n; ++j)
			cout << f[j] << " ";
		cout << endl;
#endif
	}
	cout << f[n+13] << endl;
	return 0;
}
