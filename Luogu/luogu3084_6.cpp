#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n, m, head, tail;
int dp[N], lef[N], rig[N], q[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n+1; ++i) rig[i] = i-1;
    for (int i = 1, l, r; i <= m; ++i) {
        cin >> l >> r;
        lef[r+1] = max(lef[r+1], l);
        rig[r] = min(rig[r], l-1);
    }
    for (int i = 1; i <= n+1; ++i)
        lef[i] = max(lef[i], lef[i-1]);
    for (int i = n; i; --i)
        rig[i] = min(rig[i], rig[i+1]);
#ifdef DEBUG
    for (int i = 1; i <= n+1; ++i) {
        printf("%d %d %d\n", i, lef[i], rig[i]);
    }
#endif

    q[++tail] = 0;
    for (int i = 1, j = 1; i <= n+1; ++i) {
        for ( ; j <= rig[i]; ++j) if (dp[j] != -1) {
            while (head < tail && dp[q[tail]] <= dp[j]) --tail;
            q[++tail] = j;
        }
        while (head < tail && q[head+1] < lef[i]) ++head;
        dp[i] = head < tail ? dp[q[head+1]]+(i != n+1) : -1;
    }
    cout << dp[n+1] << endl;
    return 0;
}
