#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d/", a);
    if (b < 0) printf("(%d)=", b);
    else printf("%d=", b);
    if (b == 0) puts("Error");
    else printf("%.2f\n", 1.0*a/b);
    return 0;
}
