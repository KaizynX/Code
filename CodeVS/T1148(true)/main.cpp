#include<iostream>
#include<cstdio>
using namespace std;
/*
Dp[i][j]  ��ʾ����i����j������

��j��������εõ����֣���һ������j+1��j-1�ڴ�����
Dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]

��j=1   ��������Ϊn��2
Dp[i][j]=dp[i-1][n]+dp[i-1][2]
��j=n   ��������Ϊn-1��1
Dp[i][j]= dp[i-1][n-1]+dp[i-1][1]
*/
int main()
{
    int f[31][31]={0};
    int n,m;
    scanf("%d%d",&n,&m);
    f[0][1]=1;
    for(int i=1;i<=m;i++)
    {
        f[i][1]=f[i-1][n]+f[i-1][2];
        f[i][n]=f[i-1][1]+f[i-1][n-1];
        for(int j=2;j<n;j++)
            f[i][j]=f[i-1][j-1]+f[i-1][j+1];
    }
    printf("%d",f[m][1]);
    return 0;
}
