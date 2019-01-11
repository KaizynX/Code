#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e3+7;

int dp[Maxn][Maxn], last[Maxn][Maxn];
string s, t;

int main()
{
    cin >> s >> t;
    //memset(last, -1, sizeof last);
    for(int i = 1; i <= s.length(); ++i)
    {
        for(int j = 1; j <= t.length(); ++j)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[s.length()][t.length()] << endl;
    return 0;
}
