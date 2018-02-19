#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxm = 16;
const int maxn = 11;
int dp[maxn][maxm], result[maxn][maxm], n, m, profit[maxn][maxm];
//dp[i][j]����j̨���ӷָ�ǰi����˾���������
//profit[i][k]��ʾ��i����˾����k̨������
void output(int x,int y)
{
	if(x==0)return;
	output(x-1, y-result[x][y]);
	printf("%d %d\n",x,result[x][y]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)scanf("%d",&profit[i][j]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=j;k++)
            {
                int val=dp[i-1][j-k]+profit[i][k];
                if(dp[i][j]<=val)
                {
                    dp[i][j]=val;
                    result[i][j]=k;
                }
            }
        }
    }
    printf("%d\n",dp[n][m]);
    output(n,m);
    return 0;
}
