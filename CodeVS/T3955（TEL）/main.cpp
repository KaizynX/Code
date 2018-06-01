//TLE
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=10;//1000000;
int main()
{
    int n,a[maxn],dp[maxn],maxdp,res=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        maxdp=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i]&&dp[j]>maxdp)maxdp=dp[j];
        }
        dp[i]=maxdp+1;
        if(dp[i]>res)res=dp[i];
    }
    printf("%d",res);
    return 0;
}
