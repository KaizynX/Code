#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int T;
string str;
int dp[N][8];

int main()
{
    cin >> T;
    while (T--) {
        cin >> str;
        int res = 0;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= (int)str.length(); ++i) {
            int v = str[i-1]-'0';
            for (int j = 0; j < 8; ++j)
                dp[i][(j*10+v)%8] += dp[i-1][j];
            ++dp[i][v%8];
            res += dp[i][0];
        }
        cout << res << endl;
    }
    return 0;
}
