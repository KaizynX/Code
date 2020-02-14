#include <bits/stdc++.h>
// #define DEBUG
using namespace std;

const int N = 2e3+7;

int T;
long long dp[N][10];
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >>s;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= s.length(); ++i) {
            int x = s[i-1]-'0';
            ++dp[i][x%8];
            for (int j = 0; j < 8; ++j) {
                dp[i][(j*10+x)%8] += dp[i-1][j];
            }
            #ifdef DEBUG
            for (int j = 0; j < 8; ++j)
                cout << dp[i][j] << " ";
            cout << endl;
            #endif
        }
        long long res = 0;
        for (int i = 1; i <= s.length(); ++i)
            res += dp[i][0];
        cout << res << endl;
    }
    return 0;
}
