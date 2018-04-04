#include <iostream>
#include <cstdio>
#define A 'A'-1
#define N '0'
using namespace std;
const int maxn=120+5;
const int maxb=200+5;
int n,b,ans;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool vis[maxn][maxn],a[maxn][maxn];
string ss;
/**   0
    3 O 1
      2   **/
inline void read();
inline void init();
inline bool walk(int &x,int &y,int &s,int d);

void dfs2(int x,int y,int s,int d,string sss)
{
    int nx=x,ny=y,ns=s,nd=d;
    if(walk(nx,ny,ns,nd) && ns-s>0)
    {
        nx-=dx[d];
        ny-=dy[d];
        dfs2(nx,ny,ns,(nd+1)%4,sss+"R");//right
        dfs2(nx,ny,ns,(nd-1+4)%4,sss+"L");//left
    }
    if(ns-s>0)//?
    {
        nx-=dx[d];
        ny-=dy[d];
    }
    if(ans<ns)
    {
        ans=ns;
        ss=sss;
    }
    while(nx!=x || ny!=y)
    {
        vis[nx][ny]=0;
        x-=dx[d];
        y-=dy[d];
    }
}

void dfs(int x,int y,int s,int d)
{
    int nx=x,ny=y,ns=s,nd=d;
    if(walk(nx,ny,ns,nd))
    {
        //right
        nd=(d+1)%4;
        if(a[nx+dx[nd]][ny+dy[nd]]==0)
            dfs(nx,ny,ns,nd);
        //left
        nd=(d-1+4)%4;
        if(a[nx+dx[nd]][ny+dy[nd]]==0)
            dfs(nx,ny,ns,nd);
    }
    if(ans<ns)
    {
        ans=ns;
    }
    while(nx!=x || ny!=y)
    {
        vis[nx][ny]=0;
        nx-=dx[d];
        ny-=dy[d];
    }
}

void print()
{
    for(int i=0;i<=n+1;++i)
    {
        for(int j=0;j<=n+1;++j)
            printf("%d ",a[i][j]);
        putchar('\n');
    }
}

int main()
{
    read();
    init();
    dfs(1,1,1,1);
    print();//
    dfs(1,1,1,2);
    printf("%d\n",ans);
    cout<<ss;//
    return 0;
}

inline void read()
{
    //freopen("1560.in","r",stdin);//
    char y;
    int x;
    scanf("%d%d",&n,&b);
    for(int i=1;i<=b;++i)
    {
        cin>>y>>x;
        y-=A;
        a[x][y]=1;
    }
}

inline void init()
{
    vis[1][1]=1;
    for(int i=1;i<=n;++i)
    {
        a[i][0]=1;
        a[i][n+1]=1;
        a[0][i]=1;
        a[n+1][i]=1;
    }
}

inline bool walk(int &x,int &y,int &s,int d)
{
    while(1)
    {
        x+=dx[d];
        y+=dy[d];
        if(vis[x][y])
        {
            x-=dx[d];
            y-=dy[d];
            return 0;
        }
        if(a[x][y])
        {
            x-=dx[d];
            y-=dy[d];
            return 1;
        }
        vis[x][y]=1;
        s++;
    }
}
