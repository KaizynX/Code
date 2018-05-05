#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 2e5 + 7;
const int INF = 0x7f7f7f7f;

int n, ans = - INF;
int a[Maxn];

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0, tmp = 0; i < n; ++i)
	{
		if(tmp < 0) tmp = 0;
		tmp += a[i];
		ans = max(ans,tmp);
	}
	cout << ans << endl;
	return 0;
}
