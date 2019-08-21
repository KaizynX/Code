#include <bits/stdc++.h>

using namespace std;

const int kN = 5e3+7;

int n, k;
int pre[kN], nex[kN];
long long ans;

struct Node
{
    int h;
    long w;
    bool operator < (const Node &nex) const { return h < nex.h; }
} a[kN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%d", &a[i].w, &a[i].h);
        pre[i] = i-1;
        nex[i] = i+1;
    }
    sort(a+1, a+n+1);
    nex[0] = 1;
    pre[n+1] = n;
    for (int i = 1; i <= n-k; ++i) {
        long long min_cost = -1, mini = -1;
        for (int j = nex[nex[0]]; j <= n; j = nex[j]) {
            long long now_cost = a[j].w*(a[j].h-a[pre[j]].h);
            if (mini == -1 || now_cost < min_cost) {
                min_cost = now_cost;
                mini = j;
            }
        }
        ans += min_cost;
        a[pre[mini]].w += a[mini].w;
        // delete mini
        pre[nex[mini]] = pre[mini];
        nex[pre[mini]] = nex[mini];
    }
    printf("%lld\n", ans);
    return 0;
}
