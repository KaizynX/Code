#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string a, b;

int main()
{
    while (cin >> a >> b) {
        int n = a.length(), m = b.length();
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
