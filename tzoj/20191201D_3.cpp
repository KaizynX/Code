#include <bits/stdc++.h>

using namespace std;

int a, b;
int mem[100], *dp = mem+50;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> a >> b) {
        int res = 0;
        memset(mem, 0x3f, sizeof mem);
        if (abs(a-b) > 10) {
            res += (abs(a-b)-5)/5;
            if (b > a) a += res*5;
            else a -= res*5;
        }
        // set a == 0
        dp[0] = 0;
        for (int i = 1; i <= 10; ++i) {
            for (int j = -20; j <= 20; ++j) {
                if (a+j < 1) continue;
                dp[max(1-a, j-5)] = min(dp[max(1-a, j-5)], dp[j]+1);
                dp[max(1-a, j+5)] = min(dp[max(1-a, j+5)], dp[j]+1);
                dp[max(1-a, j-2)] = min(dp[max(1-a, j-2)], dp[j]+1);
                dp[max(1-a, j+2)] = min(dp[max(1-a, j+2)], dp[j]+1);
                /*
                dp[j] = min(dp[j], dp[j-5]+1);
                dp[j] = min(dp[j], dp[j+5]+1);
                dp[j] = min(dp[j], dp[j-2]+1);
                dp[j] = min(dp[j], dp[j+2]+1);
                */
            }
        }
        cout << res+dp[b-a] << endl;
    }
    return 0;
}

