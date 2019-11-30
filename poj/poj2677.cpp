#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+7;
const int INF = 1e9;

int n;
double dp[N][N];

struct Node
{
    int x, y;
    friend bool operator < (const Node &a, const Node &b) {
        return a.x < b.x;
    }
} a[N];

inline double dis(int i, int j) {
    return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; ++i)
            scanf("%d %d", &a[i].x, &a[i].y);
        sort(a+1, a+n+1);
        dp[2][1] = dis(1, 2);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i-1; ++j)
                dp[i][j] = dp[i-1][j]+dis(i-1, i);
            dp[i][i-1] = INF;
            for (int k = 1; k < i-1; ++k)
                dp[i][i-1] = min(dp[i][i-1], dp[i-1][k]+dis(k, i));
        }
        dp[n][n] = dp[n][n-1]+dis(n-1, n);
        printf("%.2f\n", dp[n][n]);
    }
    return 0;
}
