#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100+5;
int n,m,ans,a[maxn][maxn],vis[maxn][maxn];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void bfs(int x,int y)
{
    vis[x][y]=1;
    int nx,ny;
    for(int i=0;i<4;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(a[nx][ny] && vis[nx][ny]==0)
            bfs(nx,ny);
    }
}

inline void read()
{
    char c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>c;
            a[i][j]=c-'0';
        }
    }
}

inline void solve()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(vis[i][j]==0 && a[i][j]!=0)
            {
                bfs(i,j);
                ans++;
            }
        }
    }
}

int main()
{
    read();
    solve();
    printf("%d\n",ans);
    return 0;
}
