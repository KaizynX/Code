#include <bits/stdc++.h>

using namespace std;

const double dis = 1e-8;
const double PI = 3.14159265358979323846264338328;

int a, b, x;
double res;

int main()
{
    scanf("%d %d %d", &a, &b, &x);
    double half = a*a*b/2;
    if (abs(half-x) < dis) {
        res = 45;
    } else if (half < x) {
        res = atan(2.0*(a*a*b-x)/a/a/a)/PI*180;
    } else if (half > x) {
        res = atan(a*b*b/2.0/x)/PI*180;
    }
    printf("%.10lf\n", res);
    return 0;
}
