#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=30+2;

int n,m[maxn][maxn],dir[4][2]={1,0,-1,0,0,1,0,-1};
bool vis[maxn][maxn];

inline void read()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&m[i][j]);
}

inline void print()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(m[i][j]==3)
                printf("0 ");
            else if(m[i][j]==0)
                printf("2 ");
            else
                printf("1 ");
        }
        printf("\n");
    }
}

void bfs(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n)
        return ;
    m[x][y]=3;
    int nx,ny;
    for(int i=0;i<4;++i)
    {
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(m[nx][ny]==0)
            bfs(nx,ny);
    }
}

inline void solve()
{
    for(int i=1;i<=n;++i)
    {
        if(m[1][i]==0)
            bfs(1,i);
        if(m[n][i]==0)
            bfs(n,i);
        if(m[i][1]==0)
            bfs(i,1);
        if(m[i][n]==0)
            bfs(i,n);
    }
}

int main()
{
    scanf("%d",&n);
    read();
    solve();
    print();
    return 0;
}
