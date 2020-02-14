#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

double m, h;

int main()
{
    scanf("%lf %lf", &m, &h);
    double res = 1.0*m/h/h;
    printf("%.1f\n", res);
    puts((res > 25 ? "PANG" : "Hai Xing"));
    return 0;
}
