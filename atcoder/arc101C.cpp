#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 1e5+7;
const int INF = 1e9;

int n, k, ans = INF;
int a[Maxn], p = -1;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        if(a[i] == 0)
        {
            k--;
            i--;
            n--;
        }
        else if(p == -1 && a[i] > 0) p = i-1;
    }
    if(p == -1) p = n;
    // a[p] < 0, a[p+1] > 0
    if(p+k <= n) ans = min(ans, a[p+k]);
    if(p-k+1 >= 1) ans = min(ans, -a[p-k+1]);
#ifdef DEBUG
    printf("%d %d\n", p, ans);
#endif
    // p+i <= n, p-(k-i)+1 >= 1
    for(int i = 1; i < k; ++i)
    {
        if(p+i <= n && p-(k-i)+1 >= 1)
            ans = min(ans, min(a[p+i], -a[p-(k-i)+1])+a[p+i]-a[p-(k-i)+1]);
#ifdef DEBUG
        printf("%d %d\n", i, ans);
#endif
    }
    printf("%d\n", ans);
    return 0;
}
