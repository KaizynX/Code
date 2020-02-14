#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e6+7;

string s;
vector<int> vec[N];
long long dp[10][26];
long long vis[10][26][26];

int main()
{
    cin >> s;
    for (int i = 0; i <= 3; ++i) vec[i].emplace_back(0);
    for (int i = 1; i <= (int)s.length(); ++i)
        for (int j = max(0, i-4); j < i; ++j)
            vec[i].emplace_back(s[j]-'a');
    dp[0][0] = 1;
    // 4 == i, 3 == i-1, 2 == i-2, 1 == i-3, 0 == i-4
    for (int i = 1, c; i <= (int)s.length(); ++i) {
        c = s[i-1]-'a';
        for (int l = 0; l <= 4; ++l) {
            if (i-5+l < 0) continue;
            for (int j : vec[i-4+l]) {
                dp[l][j] = dp[l+1][j];
                for (int k : vec[i-5+l])
                    vis[l][j][k] = vis[l+1][j][k];
            }
        }
        for (int l = 4; l; --l) {
            if (i-5+l < 0) continue;
            for (int j : vec[i-5+l]) {
                long long tmp = dp[l-1][j]-vis[l][c][j];
                dp[l][c] += tmp;
                vis[l][c][j] += tmp;
            }
        }
#ifdef DEBUG
        for (int j = 0; j < 3; ++j) {
            cout << dp[4][j] << " \n"[j==2];
        }
#endif
    }
    long long res = 0;
    for (int i = 4; i; --i)
        for (int j = 0; j < 26; ++j)
            res += dp[i][j];
    cout << res << endl;
    return 0;
}

