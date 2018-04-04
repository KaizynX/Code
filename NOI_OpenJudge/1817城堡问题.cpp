#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=50+5;
const int w[]={8,4,2,1};
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
/**
  2
3 A 1
  0
**/
int n,m,v,ans,maxv;
int a[maxn][maxn][4];
bool vis[maxn][maxn];

inline void in();
inline void set_side();
inline void set_wall(int x,int y,int wall);

void dfs(int x,int y)
{
    int nx,ny;
    vis[x][y]=1;
    v++;
    for(int i=0;i<4;++i)
    {
        if(a[x][y][i]==1)
            continue;
        nx=x+dx[i];
        ny=y+dy[i];
        if(vis[nx][ny]==1)
            continue;
        if(nx<1 || nx>n || ny<1 || n>m)
            continue;
        dfs(nx,ny);
    }
}

int main()
{
    in();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(vis[i][j]==0)
            {
                v=0;
                dfs(i,j);
                ans++;
                maxv=max(v,maxv);
            }
        }
    }
    printf("%d\n%d\n",ans,maxv);
    return 0;
}

inline void set_wall(int x,int y,int wall)
{
    for(int i=0;i<4;++i)
    {
        if(wall>=w[i])
        {
            wall-=w[i];
            a[x][y][i]=1;
        }
    }
}

inline void in()
{
    int wall;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&wall);
            set_wall(i,j,wall);
        }
    }
}
