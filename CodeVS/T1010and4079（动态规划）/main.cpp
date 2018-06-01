#include <iostream>

using namespace std;
const int maxn=17;
int main()
{
    int n,m,x,y,a[maxn][maxn]={0},b[maxn][maxn]={0};
    cin>>n>>m>>x>>y;
    a[x][y]=1;
    a[x-1][y+2]=1;
    a[x-1][y-2]=1;
    a[x+1][y+2]=1;
    a[x+1][y-2]=1;
    a[x-2][y+1]=1;
    a[x-2][y-1]=1;
    a[x+2][y+1]=1;
    a[x+2][y-1]=1;
    b[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(a[i][j]==0)
            {
                if(a[i-1][j]==0)b[i][j]+=b[i-1][j];//up
                if(a[i][j-1]==0)b[i][j]+=b[i][j-1];//left
            }
        }
    }
    cout<<b[n][m]<<endl;
    return 0;
}
