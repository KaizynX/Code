#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int T, n, top;
int a[N], dfn[N], sta[N];

bool dfs(int cur, int dep)
{
    if (dfn[cur]) {
        printf("%d\n", dep-dfn[cur]);
        while (sta[top] != cur)
            printf("%d ", sta[top--]);
        printf("%d\n", cur);
        return true;
    }
    dfn[cur] = dep;
    sta[++top] = cur;
    if (dfs(cur-a[cur], dep+1)) return true;
    --top;
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        top = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            dfn[i] = 0;
        }
        for (int i = 1; i <= n; ++i) if (!dfn[i]) {
            if (dfs(i, 1)) break;
        }
    }
    return 0;
}

