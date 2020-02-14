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
            double tmp = n*p;
            sprintf(buf, "%.1f", tmp);
            sscanf(buf, "%lf", &tmp);
            sum += tmp;
        }
        printf("%.1f\n", sum);
    }
    return 0;
}
