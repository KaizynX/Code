#include <bits/stdc++.h>
using namespace std;
int n, k;
inline long long calc(int x) { return 1ll*x*x*x; }

int main()
{
	cin >> n >> k;
	if(k&1) cout << calc(n/k) << endl;
	else cout << calc(n/k)+calc(n/(k/2)-n/k) << endl;
	return 0;
}
