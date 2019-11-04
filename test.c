#include <stdio.h>

int main()
{
    int n;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        sum += 2.0/(i+2*i-1)/i;
    }
    printf("sum = %.6f\n", sum);
    return 0;
}
