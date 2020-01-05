#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 5e3+7;

int n, k;
int dp[N][M];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n/100; ++i) {
        for (int j = 0; j <= 5; ++j) {
            for (int k = j; k <= 5*i; ++k) {
                dp[i][k] |= dp[i-1][k-j];
            }
        }
    }
    for (int i = 0; i <= n/100; ++i) {
        if (dp[i][n-100*i]) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
