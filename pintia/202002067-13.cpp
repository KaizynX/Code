#include <bits/stdc++.h>

using namespace std;

int w, p;
double s, k, res;

int main()
{
    scanf("%d%d", &w, &p);
    s = 200000.0/9.8/w;
    k = (100.0-p)/100.0;
    while (s > 1e-5) {
        res += s;
        s *= k;
    }
    printf("%.3f\n", res);
    return 0;
}
