#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int t[N], s[N], vis[N];

int main()
{
    while (scanf("%d", &n) == 1) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", t+i, s+i);
            vis[i] = 0;
        }
        for (int i  = n; i; --i) {
            int mvi = -1;
            for (int j = 1; j <= n; ++j) {
                if (vis[j] || t[j] < i) continue;
                if (mvi == -1 || s[j] > s[mvi]) mvi = j;
            }
            if (mvi != -1) {
                vis[mvi] = 1;
                res += s[mvi];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
