#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 2e5+7;
const int INF = 0x3f3f3f3f;

int n, l, r, ans = -INF;
int a[Maxn], f[Maxn];
int head, tail;
pair<int, int> q[Maxn];

int main()
{
    scanf("%d%d%d", &n, &l, &r);
    for(int i = 0; i <= n; ++i)
        scanf("%d", a+i);
    // q[0] = make_pair(0, 0);
    for(int i = l; i <= n; ++i)
    {
        if(q[head].second < i-r) head++;
        while(head <= tail && q[tail].first < f[i-l]) tail--;
        q[++tail] = make_pair(f[i-l], i-l);
#ifdef DEBUG
        printf("%d %d\n", i, q[head].second);
#endif
        f[i] = q[head].first+a[i];
        if(i > n-r) ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}
