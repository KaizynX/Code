#include <iostream>

using namespace std;
const int big=10000000;
int a[101],f[101][101],sum[101][101];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            sum[i][j]=sum[i][j-1]+a[j];
     for(int len=2;len<=n;len++)//归并的石子长度
    {
        for(int i=1;i<=n-len+1;i++)//i为起点，j为终点
        {
            int j=i+len-1;
            f[i][j]=big;
            for(int k=i;k<=j-1;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[i][j]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}
