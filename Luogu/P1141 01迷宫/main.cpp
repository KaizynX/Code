#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+5;
const int maxm=100000+5;

int n,m,ans;
int a[maxn][maxn],res[maxn*maxn],ask[maxm][2];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool vis[maxn][maxn],que[maxn][maxn];
int f[maxn*maxn];

inline void init();
inline int change(int x,int y);
inline int getint();
inline void read();
inline void print();

void bfs(int x,int y,int bx,int by)
{
    if(x<1 || x>n || y<1 || y>n)
        return;
    if(vis[x][y])
        return ;
    ans++;
    vis[x][y]=1;
    int now=a[x][y],nx,ny;
    now=(now+1)%2;
    for(int i=0;i<4;++i)
    {
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(a[nx][ny]==now)
        {
            f[change(nx,ny)]=change(bx,by);
            bfs(nx,ny,bx,by);
        }
    }
}

inline void solve()
{
    int pos;
    init();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            pos=change(i,j);
            if(que[i][j]==0 || res[f[pos]]!=0)
                continue;
            ans=0;
            bfs(i,j,i,j);
            res[pos]=ans;
        }
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

inline void init()
{
    for(int i=1;i<=n*n;++i)
        f[i]=i;
}

inline int change(int x,int y)
{
    return (x-1)*n+y;
}

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

inline void print()
{
    int x,y,pos;
    for(int i=1;i<=m;++i)
    {
        x=ask[i][0];
        y=ask[i][1];
        pos=change(x,y);
        printf("%d\n",res[f[pos]]);
    }
}
/**RE
10 4
1010101010
0101010101
1010101010
0101010101
1010101110
0100101111
1011001110
0100010001
1011101110
0100101001
3 4
1 2
10 4
4 1
**/
