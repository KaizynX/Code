#include <iostream>
using namespace std;
int n,m,a[11][17],res[11][17],dp[11][17];
void out(int x,int y);
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=j;k++)
            {
                if(res[i-1][j-k]+a[i][k]>=res[i][j])
                {
                    res[i][j]=res[i-1][j-k]+a[i][k];
                    dp[i][j]=k;
                }
            }
        }
    }
    cout<<res[n][m]<<endl;
    out(n,m);
}
void out(int x,int y)
{
    if(x==0)return;
    out(x-1,y-dp[x][y]);
    cout<<x<<" "<<dp[x][y]<<endl;
}
