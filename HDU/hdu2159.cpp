#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 123;
const int INF = 0x3f3f3f3f;

int n, m, k, s;
// dp[i][j] kill i's get j exp min tolerate
int dp[N][N];

#ifdef DEBUG
inline void print()
{
    for (int i = 0; i <= s; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("%3d ", dp[i][j] == INF ? -1 : dp[i][j]);
        }
        putchar('\n');
    }
    puts("********");
}
#endif

int main()
{
    while (scanf("%d %d %d %d", &n, &m, &k, &s) == 4) {
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1, a, b; i <= k; ++i) {
            scanf("%d %d", &a, &b);
            for (int j = 1; j <= s; ++j) {
                for (int v = 0; v <= n+20; ++v)
                    dp[j][v] = min(dp[j][v], dp[j-1][v]);
                for (int v = a; v <= n+20; ++v) 
                    dp[j][v] = min(dp[j][v], dp[j-1][v-a]+b);
            }
#ifdef DEBUG
            print();
#endif
        }
        int res = INF;
        for (int v = n; v <= n+20; ++v) res = min(res, dp[s][v]);
        cout << (res > m ? -1 : m-res) << endl;
    }
    return 0;
}
