#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 50;

int n, tot;
long long S, a[Maxn], ans, all;

void solve(int cur, long long sum)
{
    if(cur > tot || sum == S)
    {
        ans = max(ans, sum);
        return;
    }
    if(sum+a[cur] <= S) solve(cur+1, sum+a[cur]);
    solve(cur+1, sum);
}

int main()
{
    scanf("%lld%d", &S, &n);
    for(int i = 1, v, w; i <= n; ++i)
    {
        scanf("%d%d", &w, &v);
        a[++tot] = w;
        for(int i = 2; i <= v; ++i)
            a[tot] *= w;
        if(a[tot] > S) tot--;
        else all += a[tot];
        if(a[tot] == S)
        {
            printf("%lld\n", S);
            return 0;
        }
    }
    if(all <= S)
    {
        printf("%lld\n", all);
        return 0;
    }
    sort(a+1, a+tot+1);
    reverse(a+1, a+tot+1);
    solve(1, 0);
    printf("%lld\n", ans);
    return 0;
}
