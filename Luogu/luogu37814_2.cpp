#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e3+7;
const double eps = 1e-10;

int n, A, B, tot;
long double a[Maxn], ans[Maxn];
// f'(x)
long double calc_(double x, int y)
{
	if(y == 0) return a[1];
	return calc_(x, y-1)+a[y+1]*(y+1)*pow(x, y);
}

// f(x)
long double calc(double x, int y)
{
	if(y == 0) return a[0];
	return calc(x, y-1)+a[y]*pow(x, y);
}

inline void Erfen(double l, double r)
{
	double mid;
	while(l+eps < r)
	{
		mid = (l+r)/2;
		if(calc_(l, n-1)*calc_(mid, n-1) <= 0) r = mid;
		else l = mid;
	}
	ans[++tot] = calc(l, n);
}

int main()
{
	cin >> n;
	for(int i = 0; i <= n; ++i)
		cin >> a[i];
	cin >> A >> B;
	for(int i = A; i < B; ++i)
		if(calc_(i, n-1)*calc_(i+1, n-1) <= 0)
			Erfen(i, i+1);
	if(!tot)
	{
		puts("Poor OIers");
		return 0;
	}
	sort(ans+1, ans+tot+1);
	for(int i = 1; i < tot; ++i)
		cout << fixed << setprecision(2) << ans[i] << " ";
	cout << fixed << setprecision(2) << ans[tot] << endl;
	return 0;
}
