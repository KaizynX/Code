#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 20;
const int INF = 1e9;

int n, m;
string s;
int dp[1<<M], cnt[M][M], num[1<<M], sum[1<<M][M];
map<char, int> mp;

int main()
{
    cin >> n >> m >> s;
    for (int i = 0, dfn = 0; i < (int)s.length(); ++i) {
        if (mp.find(s[i]) == mp.end()) mp[s[i]] = dfn++;
    }
    for (int i = 1; i < (int)s.length(); ++i) {
        ++cnt[mp[s[i]]][mp[s[i-1]]];
        ++cnt[mp[s[i-1]]][mp[s[i]]];
    }
    for (int i = 0; i < (1<<m); ++i) {
        num[i] = 0;
        for (int j = 0; j < m; ++j) {
            if ((i>>j)&1) {
                ++num[i];
            } else {
                for (int k = 0; k < m; ++k) {
                    if ((i>>k)&1)
                        sum[i][j] += cnt[j][k];
                }
            }
        }
    }
    int B = (1<<m)-1;
    for (int i = 1; i < (1<<m); ++i) {
        dp[i] = INF;
        for (int j = 0; j < m; ++j) {
            if ((i>>j)&1) {
                int last = i^(1<<j);
                dp[i] = min(dp[i], dp[last]+num[i]*(sum[last][j]-sum[B^i][j]));
            }
        }
    }
    cout << dp[B] << endl;
    return 0;
}
