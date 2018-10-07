#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const double eps=1e-15;

int n,L,R,cnt;
long double a[1005],b[1005],ans[1005];

long double calc_(double x,int y)
{
    if(y == 0) return b[0];
    return calc_(x, y-1)+b[y]*pow(x, y);
}

long double calc(double x,int y)
{
    if(y == 0) return a[0];
    return calc(x, y-1)+a[y]*pow(x, y);
}

void Erfen(double l,double r)
{
    double mid;
    while (l+eps<r) {
        mid = (l+r)/2;
        if(calc(l, n-1)*calc(mid, n-1) <= 0) r = mid;
        else l = mid;
    }
    ans[++cnt] = calc(l, n);
}
int main()
{
    cin >> n;
    cin >> a[0];
    for(int i = 1; i <= n; i++)
	{
        cin >> a[i];
		b[i-1] = a[i]*i;
	}
    cin >> L >> R;
    for(int i = L; i <= R-1; i++)
        if(calc(i, n-1)*calc(i+1, n-1) <= 0)
            Erfen(i, i+1);
    if(!cnt)
	{
        puts("Poor OIers");
        return 0;
    }
    sort(ans+1, ans+cnt+1);
    for(int i = 1; i <= cnt; i++)
        printf("%.2Lf ", ans[i]);
    return 0;
}
