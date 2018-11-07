#include <bits/stdc++.h>

using namespace std;

const double oula = 0.57721566490153286060651209;

int n;
double sum, f;

int main()
{
    scanf("%d", &n);
    if(n == 1) return puts("0.00000")&0;
    else if(n <= 1e6)
    {
        f = sum = 1;
        for(int i = 2; i <= n; ++i)
            f = sum/(i-1)+1, sum += f;
        printf("%.5f\n", f);
    }
    else printf("%.5f\n", log(n)+oula+1);
    return 0;
}
