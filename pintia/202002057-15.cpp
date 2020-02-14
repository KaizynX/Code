#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n;
long long x[N], y[N];

inline long long calc(const int &i, const int &j, const int &k)
{
    // return x[i]*y[j]-x[i]*y[k]+x[j]*y[k]-x[j]*y[i]+x[k]*y[i]-x[j]*y[j];
    return x[i]*y[j]+y[i]*x[k]+x[j]*y[k]-x[i]*y[k]-y[i]*x[j]-y[j]*x[k];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld %lld", x+i, y+i);
    long long res = calc(1, 2, 3);
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j)
            for (int k = j+1; k <= n; ++k)
                res = min(res, abs(calc(i, j, k)));
    printf("%.3f\n", res/2.0);
    return 0;
}
