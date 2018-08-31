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
inline long double calc_(double x)
{
	long double res = 0, cnt = 1;
	for(int i = 1; i <= n; ++i)
	{
		res += a[i]*cnt*i;
		cnt *= x;
	}
	return res;
}
// f(x)
inline long double calc(double x)
{
	long double res = 0, cnt = 1;
	for(int i = 0; i <= n; ++i)
	{
		res += a[i]*cnt;
		cnt *= x;
	}
	return res;
}

inline void Erfen(double l, double r)
{
	double mid;
	while(l+eps < r)
	{
		mid = (l+r)/2;
		if(calc_(l)*calc_(mid) <= 0) r = mid;
		else l = mid;
	}
	ans[++tot] = calc(l);
}

int main()
{
	cin >> n;
	for(int i = 0; i <= n; ++i)
		cin >> a[i];
	cin >> A >> B;
	for(int i = A; i < B; ++i)
		if(calc_(i)*calc_(i+1) <= 0)
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
