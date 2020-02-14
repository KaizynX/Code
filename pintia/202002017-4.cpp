#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int res = 1;
    for (int i = 1; i <= n; ++i)
        res <<= 1;
    printf("2^%d = %d\n", n, res);
    return 0;
}
