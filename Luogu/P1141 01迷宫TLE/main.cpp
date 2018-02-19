#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=1000+5;
const int maxm=100000+5;

int n,m,ans;
int a[maxn][maxn],res[maxn][maxn],ask[maxm][2];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool vis[maxn][maxn],que[maxn][maxn];
queue<int> qx,qy;

int getint()
{
    int res=0;
    char c=getchar();
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

inline void read()
{
    char c;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            c=getchar();
            while(c!='1' && c!='0')
                c=getchar();
            if(c=='1')
                a[i][j]=1;
        }
    }
}

void bfs(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n)
        return;
    if(vis[x][y])
        return ;
    ans++;
    vis[x][y]=1;
    qx.push(x);
    qy.push(y);
    int now=a[x][y],nx,ny;
    now=(now+1)%2;
    for(int i=0;i<4;++i)
    {
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(a[nx][ny]==now)
            bfs(nx,ny);
    }
}

inline void solve()
{
    int x,y;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(que[i][j]==0 || res[i][j]!=0)
                continue;
            ans=0;
            memset(vis,0,sizeof vis);
            if(res[i][j]==0)
                bfs(i,j);
            while(!qx.empty())
            {
                x=qx.front();
                qx.pop();
                y=qy.front();
                qy.pop();
                res[x][y]=ans;
            }
        }
    }
}

inline void print()
{
    int x,y;
    for(int i=1;i<=m;++i)
    {
        x=ask[i][0];
        y=ask[i][1];
        printf("%d\n",res[x][y]);
    }
}

int main()
{
    int i,bx,by;
    n=getint();
    m=getint();
    read();
    for(i=1;i<=m;++i)
    {
        bx=getint();
        by=getint();
        que[bx][by]=1;
        ask[i][0]=bx;
        ask[i][1]=by;
    }
    solve();
    print();
    return 0;
}
