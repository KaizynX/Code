#include <iostream>
#include <cstdio>
#define NO "no way.\n"
using namespace std;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};

const int maxn=1000+5;

int n,m,bx,by,ex,ey;
int a[maxn][maxn],nex[maxn][maxn];
bool vis[maxn][maxn],flag=0;;

inline void in();

inline void print()
{
    int d,x=bx,y=by;
    while(1)
    {
        printf("%d,%d\n",x,y);
        if(x==ex && y==ey)return;
        d=nex[x][y];
        x+=dx[d];
        y+=dy[d];
    }
}

void dfs(int x,int y)
{
    int nx,ny;
    vis[x][y]=1;
    for(int d=0;d<4;++d)
    {
        if(flag)return;//had found
        nx=x+dx[d];
        ny=y+dy[d];
        if(nx==ex && ny==ey)
        {
            nex[x][y]=d;
            print();
            flag=1;
            return;
        }
        if(nx<1 || nx>n || ny<1 || ny>m)
            continue;
        if(a[nx][ny]==-1)
            continue;
        if(vis[nx][ny]==1)
            continue;
        //vis[nx][ny]=1;
        nex[x][y]=d;
        dfs(nx,ny);
        //vis[nx][ny]=0;
    }
    vis[x][y]=0;
}

int main()
{
    in();
    dfs(bx,by);
    if(flag==0)
        printf(NO);
    return 0;
}

inline void in()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d%d%d%d",&bx,&by,&ex,&ey);
}
