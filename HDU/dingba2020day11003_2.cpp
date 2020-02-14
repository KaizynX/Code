#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

int T, n;

inline int f(int x)
{
    if (x <= 1) return 0;
    int res = 1;
    for (int i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        res += x/i;
        if (x/i != i) res += i;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int m = f(n), k = f(m);
        if (n == m || m > N || m < 1) puts("注定单身");
        else if (n == k) puts("缘分已定");
        else puts("缘分未到");
    }
    return 0;
}
