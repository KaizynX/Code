#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
bool dp[1<<N][20];
int path[1<<N][20];
char a[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", a[i]);
    // start from 1
    for (int i = 0; i < n; ++i) dp[0][0] = true;
    for (int i = 1, last; i < 1<<n; ++i) {
        for (int j = 0; j < n; ++j) if ((i>>j)&1) {
            last = i^(1<<j);
            for (int k = 0; k < n; ++k) if ((a[j][k] == 'W' || a[k][j] == 'L')&& dp[last][k]) {
                if (!dp[i][j]) {
                    dp[i][j] = true;
                    path[i][j] = k;
                } else {
                    path[i][j] = min(path[i][j], k);
                }
            }
        }
    }
    if (!dp[(1<<n)-1][0]) return puts("No Solution")&0;
    for (int i = 0, j = (1<<n)-1, tmp; j; ) {
        printf("%d", i+1);
        tmp = j;
        j ^= 1<<i;
        putchar((j ? ' ' : '\n'));
        i = path[tmp][i];
    }
    return 0;
}
