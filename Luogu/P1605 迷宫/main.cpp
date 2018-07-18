#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5+5;

int n,m,t,ans,sx,sy,fx,fy;
bool a[maxn][maxn],vis[maxn][maxn];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

void dfs(int x,int y)
{
    if(x==fx && y==fy)
    {
        ans++;
        return;
    }
    int nx,ny;
    vis[x][y]=1;
    for(int i=0;i<4;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(a[nx][ny] || vis[nx][ny])
            continue;
        dfs(nx,ny);
    }
    vis[x][y]=0;
}

inline void init()
{
    int i;
    for(i=1;i<=m;++i)
    {
        a[0][i]=1;
        a[n+1][i]=1;
    }
    for(i=1;i<=n;++i)
    {
        a[i][0]=1;
        a[i][m+1]=1;
    }
}

int main()
{
    int x,y;
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i=1;i<=t;++i)
    {
        scanf("%d%d",&x,&y);
        a[x][y]=1;
    }
    init();
    dfs(sx,sy);
    printf("%d\n",ans);
    return 0;
}
