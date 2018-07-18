#include <iostream>

using namespace std;
int dp[5001],a[5001];
int main()
{
    int n,res=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int m=0;
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]<a[i]&&dp[j]>m)m=dp[j];
        }
        dp[i]=m+1;
        res=max(dp[i],res);
    }
    cout<<res<<endl;
    return 0;
}
