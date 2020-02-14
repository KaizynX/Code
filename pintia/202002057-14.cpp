#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;

string s;
long long dp[N][26];
long long vis[N][26][26];

int main()
{
    cin >> s;
    dp[0][0] = 1;
    for (int i = 1, c; i <= (int)s.length(); ++i) {
        c = s[i-1]-'a';
        for (int l = i; l >= i-3 && l > 0; --l) {
            for (int j = 0; j < 3; ++j) {
                if (dp[l-1][j]) {
                    long long tmp = dp[l-1][j]-vis[l][c][j];
                    dp[l][c] += tmp;
                    vis[l][c][j] += tmp;
                }
            }
        }
    }
#ifdef DEBUG
    for (int i = 1; i <= (int)s.length(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << dp[i][j] << " \n"[j==2];
        }
    }
#endif
    long long res = 0;
    for (int i = (int)s.length(); i >= (int)s.length()-3; --i)
        for (int j = 0; j < 26; ++j)
            res += dp[i][j];
    cout << res << endl;
    return 0;
}
