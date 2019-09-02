#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int n, m;
int a[MAXN], b[MAXN], vis[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", b+i);
    }
    for (int i = m; i; --i) {
        if (!vis[b[i]]) {
            vis[b[i]] = 1;
            printf("%d ", b[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[a[i]]) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
