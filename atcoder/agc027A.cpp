#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e2+7;

int n, x, ans;
int a[Maxn];

int main()
{
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; ++i)
        scanf("%d", a+i);
    sort(a, a+n);
    for(int i = 0; i < n && x >= a[i]; ++i)
    {
        x -= a[i];
        // fit the last one
        if(i != n-1 || x == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
