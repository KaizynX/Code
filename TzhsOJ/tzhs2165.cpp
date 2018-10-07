#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5+7;

int n, ans, a[Maxn], b[Maxn];

inline int abs(int a)
{
    return a < 0 ? -a : a;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d%d", a+i, b+i);
    sort(a, a+n); sort(b, b+n);
    for(int i = 0; i < n; ++i)
        ans += a[i] == b[i] ? -1 : abs(a[i] - b[i]);
    printf("%d\n", ans);
    return 0;
}
