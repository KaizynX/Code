#include <bits/stdc++.h>

using namespace std;

int T, n;
double p;
char buf[20], name[20];

int main()
{
    while (scanf("%d", &T) == 1) {
        double sum = 0;
        for (int i = 1; i <= T; ++i) {
            scanf("%s%d%lf", name, &n, &p);
            sum += round(n*p*10)/10;
        }
        printf("%.1f\n", sum);
    }
    return 0;
}
