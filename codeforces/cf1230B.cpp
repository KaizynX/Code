#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k;
char a[N];

int main()
{
    scanf("%d%d%s", &n, &k, a+1);
    if (!k) return printf("%s\n", a+1)&0;
    if (n == 1 && a[1] != '0') {
        a[1] = '0';
        --k;
    }
    if (n > 1 && a[1] != '1') {
        a[1] = '1';
        --k;
    }
    for (int i = 2; i <= n && k; ++i) {
        if (a[i] != '0') {
            a[i] = '0';
            --k;
        }
    }
    printf("%s\n", a+1);
    return 0;
}
