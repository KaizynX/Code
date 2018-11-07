#include <bits/stdc++.h>

using namespace std;

int n;
double sum, f;

int main()
{
    scanf("%d", &n);
    if(n == 1) return puts("0.00000")&0;
    f = sum = 1;
    for(int i = 2; i <= n; ++i)
        f = sum/(i-1)+1, sum += f;
    printf("%.5f\n", f);
    return 0;
}
