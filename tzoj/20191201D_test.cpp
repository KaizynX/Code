#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n;
int mem[N], *dp = mem+233;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(mem, 0x3f, sizeof mem);
    dp[0] = 0;
    /*
    for (int i = 1; i <= 20; ++i) {
        for (int j = -200; j <= 200; ++j) {
            dp[j] = min(dp[j], dp[j-5]+1);
            dp[j] = min(dp[j], dp[j+5]+1);
            dp[j] = min(dp[j], dp[j-2]+1);
            dp[j] = min(dp[j], dp[j+2]+1);
        }
    }
    */
    for (int i = 1; i <= 20; ++i) {
        for (int j = -200; j <= 200; ++j) {
            dp[j] = min(dp[j], dp[j-5]+1);
            dp[j] = min(dp[j], dp[j+5]+1);
            dp[j] = min(dp[j], dp[j-2]+1);
            dp[j] = min(dp[j], dp[j+2]+1);
        }
    }
    for (int i = -20; i <= 20; ++i) {
        cout << i << " " << dp[i] << endl;
    }
    return 0;
}


