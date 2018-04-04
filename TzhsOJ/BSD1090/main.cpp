#include <iostream>

using namespace std;
int dp[205][205];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==j)dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
