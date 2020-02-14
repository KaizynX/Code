#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 5e3+7;
const int INF = 0x3f3f3f3f;

int n;
int a[N], b[N];
// dp[i][j] ��ʾ����ǰi����������һ������jʱ���״̬�� �ڶ����˵�����ʱ��
int dp[N][M];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        // ����һ���˴���
        for (int j = a[i]; j <= 5000; ++j)
            dp[i][j] = min(dp[i][j], dp[i-1][j-a[i]]);
        // ���ڶ����˴���
        for (int j = 0; j <= 5000; ++j)
            dp[i][j] = min(dp[i][j], dp[i-1][j]+b[i]);
    }
    int res = INF;
    for (int j = 0; j <= 5000; ++j)
        res = min(res, max(j, dp[n][j]));
    cout << res << endl;
    return 0;
}
