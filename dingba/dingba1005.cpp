#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    while (scanf("%d", &n) == 1) {
        double d = 0, h = 100;
        for (int i = 1; i <= n; ++i) {
            d += h;
            h /= 2;
            d += h;
        }
        d -= h;
        printf("distance=%.1f height=%.1f\n", d, h);
    }
    return 0;
}
