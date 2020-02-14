#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main()
{
    scanf("%d", &n);
    while (n--) {
        scanf("%d/%d", &a, &b);
        int g = __gcd(a, b);
        a /= g;
        b /= g;
        printf("%d/%d\n", a, b);
    }
    return 0;
}
