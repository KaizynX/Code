#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4+7;

int T, n;
double a[MAXN];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", a+i);
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        double p0 = 1.0-a[1], p1 = a[1];
        for (int i = 2; i <= n; ++i) {
            if (p0 <= p1) break;
            p1 = p1*(1.0-a[i])+p0*a[i];
            p0 = p0*(1.0-a[i]);
        }
        printf("%.12lf\n", p1);
    }
    return 0;
}
