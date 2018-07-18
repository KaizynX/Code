#include <iostream>

using namespace std;
int n,a[101],dp[101];

int sheng(int s)
{
    int maxl=1;
    for(int i=1;i<=n;i++)dp[i]=1;
    for(int i=2;i<=s;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]<a[i]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                maxl=max(maxl,dp[i]);
            }
        }
    }
    return maxl;
}

int jiang(int s)
{
    int maxl=1;
    for(int i=1;i<=n;i++)dp[i]=1;
    for(int i=s+1;i<=n;i++)
    {
        for(int j=s;j<=i-1;j++)
        {
            if(a[j]>a[i]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                maxl=max(maxl,dp[i]);
            }
        }
    }
    return maxl;
}

int main()
{
    cin>>n;
    int ans=100;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int cur=1;cur<=n;cur++)
    {
        int up=sheng(cur);
        int down=jiang(cur);
        if(up&&down)ans=min(ans,n-up-down+1);
        else ans=min(ans,n-up-down);
    }
    cout<<ans<<endl;
    return 0;
}
