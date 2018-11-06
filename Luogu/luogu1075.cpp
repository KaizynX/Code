#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int n;
int p;

int main()
{
    scanf("%d", &n);
    for(int i = 2; i*i <= n; ++i)
        while(n%i == 0) n /= i, p = i;
    printf("%d\n", max(n, p));
    return 0;
}
