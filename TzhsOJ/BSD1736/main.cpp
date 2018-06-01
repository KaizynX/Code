#include <iostream>

using namespace std;

int main()
{
    int n,m,a[11][17]={0},b[11][17]={0},flag[11];
    int maxn,biaoji,res=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        flag[i]=1;
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j]-a[i][j-1];
        }
    }
    int m2=m;
    while(m2--)
    {
        maxn=0;
        for(int i=1;i<=m;i++)//找出最大的
        {
            if(b[i][flag[i]]>maxn)
            {
                maxn=b[i][flag[i]];
                biaoji=i;
            }
        }
        res+=maxn;
        flag[biaoji]++;
    }
    cout<<res<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<flag[i]-1<<endl;
    }
    return 1;
}
