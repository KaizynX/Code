#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
int a[Maxn][3];
int dp[Maxn][3];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> a[i][j];
    //yesterday play 'k', today play 'j' 
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            for(int k = 0; k < 3; ++k)
                if(j != k)
                    dp[i][j] = max(dp[i][j], dp[i-1][k]+a[i][j]);
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}
