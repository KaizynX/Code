#include <bits/stdc++.h>

using namespace std;

const int Maxn = 50;

int C, n;
long long dp[Maxn][10];

/* 0  1  2  3  4  5  6  7  8
   00 01 02 10 11 12 20 21 22
*/

int main()
{
    cin >> C;
    for(int i = 0; i < 9; ++i) dp[2][i] = 1;
    for(int i = 3; i < 40; ++i)
    {
        dp[i][0] = dp[i-1][0]+dp[i-1][3]+dp[i-1][6];
        dp[i][1] = dp[i-1][0]+dp[i-1][3];
        dp[i][2] = dp[i-1][0]+dp[i-1][6];
        dp[i][3] = dp[i-1][1]+dp[i-1][4];
        dp[i][4] = dp[i-1][1]+dp[i-1][4]+dp[i-1][7];
        dp[i][5] = dp[i-1][4]+dp[i-1][7];
        dp[i][6] = dp[i-1][2]+dp[i-1][8];
        dp[i][7] = dp[i-1][5]+dp[i-1][8];
        dp[i][8] = dp[i-1][2]+dp[i-1][5]+dp[i-1][8];
    }
    while(C--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << 3 << endl;
            continue;
        }
        long long sum = 0;
        for(int i = 0; i < 9; ++i)
            sum += dp[n][i];
        cout << sum << endl;
    }
    return 0;
}