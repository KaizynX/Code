#include <iostream>
#include <algorithm>
using namespace std;

struct bridge
{
    int x,y;
}b[5000];

int cmp(bridge a,bridge b)
{
    if(a.x!=b.x)return a.x<b.x;
    else return a.y<a.y;
}

int main()
{
    int dp[5000],n,maxn=1;//5000
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b[i].x>>b[i].y;
        dp[i]=1;
    }
    sort(b,b+n,cmp);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            if(b[j].y<b[i].y&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                maxn=max(dp[i],maxn);
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}
