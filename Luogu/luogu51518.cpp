#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int n, ans;
int p[Maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1, a; i <= n; ++i)
    {
        scanf("%d", &a);
        p[a] = i;
    }
    ans = abs(p[1]-p[n]);
    for(int i = 2; i <= n; ++i)
        ans = max(ans, abs(p[i]-p[i-1]));
    printf("%d\n", ans-1);
    return 0;
}
