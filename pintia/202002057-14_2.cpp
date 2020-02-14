#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

string s;
long long dp[10][26];
long long vis[10][26][26];

int main()
{
    cin >> s;
    dp[0][0] = 1;
    for (int i = 1, c; i <= 4; ++i) {
        c = s[i-1]-'a';
        for (int l = i; l >= i-3 && l > 0; --l) {
            for (int j = 0; j < 26; ++j) {
                if (dp[l-1][j]) {
                    long long tmp = dp[l-1][j]-vis[l][c][j];
                    dp[l][c] += tmp;
                    vis[l][c][j] += tmp;
                }
            }
        }
    }
    // 4 == i, 3 == i-1, 2 == i-2, 1 == i-3, 0 == i-4
    for (int i = 5, c; i <= (int)s.length(); ++i) {
        c = s[i-1]-'a';
        for (int l = 0; l <= 4; ++l) {
            for (int j = 0; j < 26; ++j) {
                dp[l][j] = dp[l+1][j];
                for (int k = 0; k < 26; ++k) {
                    vis[l][j][k] = vis[l+1][j][k];
                }
            }
        }
        for (int l = 4; l; --l) {
            for (int j = 0; j < 26; ++j) {
                if (dp[l-1][j]) {
                    long long tmp = dp[l-1][j]-vis[l][c][j];
                    dp[l][c] += tmp;
                    vis[l][c][j] += tmp;
                }
            }
        }
    }
    long long res = 0;
    for (int i = 4; i; --i)
        for (int j = 0; j < 26; ++j)
            res += dp[i][j];
    cout << res << endl;
    return 0;
}

