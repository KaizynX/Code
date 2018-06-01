#include <iostream>
//http://blog.csdn.net/athenaer/article/details/8265234
/*
第一类: n 份中不包含 1 的分法，为保证每份都 >= 2，可以先拿出 k 个 1 分
   　　到每一份，然后再把剩下的 n- k 分成 k 份即可，分法有: dp[n-k][k]
第二类: n 份中至少有一份为 1 的分法，可以先那出一个 1 作为单独的1份，剩
   　　下的 n- 1 再分成 k- 1 份即可，分法有：dp[n-1][k-1]
*/
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
