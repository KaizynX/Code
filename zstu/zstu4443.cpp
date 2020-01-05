#include <bits/stdc++.h>

using namespace std;

int T, n;

int solve(int n, int v) {
    return n == 1 ? 0 : (solve(n-1, v)+v)%n;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", solve(n, 233)+1);
    }
    return 0;
}

