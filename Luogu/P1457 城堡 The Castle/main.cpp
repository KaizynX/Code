#include <iostream>
#include <cstdio>
#define change(x,y) ((x-1)*m+y)
using namespace std;
const int maxn=50+5;
const int maxq=2500+5;
const int w[]={8,4,2,1};
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
/**
  2
3 A 1
  0
**/
int n,m,nv,ans,maxv;
int bi,bj,bd,bv;//break
int a[maxn][maxn][4];
int v[maxn][maxn];
bool vis[maxn][maxn];
int qx1[maxq],qx2[maxq],qy1[maxq],qy2[maxq];
int head,tail;
int f[maxn*maxn];

inline void in();
inline void find_room();
inline void set_wall(int x,int y,int wall);
inline void init();
int ff(int s);
inline void connect();
inline void q_push(int x,int y);
inline void q1_pop(int &x,int &y);
inline void q2_pop(int &x,int &y);

void dfs(int bx,int by)
{
    int x,y,nx,ny,fa;
    head=0;
    tail=0;
    vis[bx][by]=1;
    nv=1;
    fa=change(bx,by);
    q_push(bx,by);
    while(head<tail)
    {
        q1_pop(x,y);
        for(int i=0;i<4;++i)
        {
            if(a[x][y][i]==1)
                continue;
            nx=x+dx[i];
            ny=y+dy[i];
            if(vis[nx][ny]==1)
                continue;
            if(nx<1 || nx>n || ny<1 || ny>m)
                continue;
            vis[nx][ny]=1;
            q_push(nx,ny);
            nv++;
        }
    }
    head=0;
    while(head<tail)
    {
        q2_pop(nx,ny);
        v[nx][ny]=nv;
        f[change(nx,ny)]=fa;
    }
}

void break_wall()
{
    int nx,ny;
    for(int j=1;j<=m;++j)
    {
        for(int i=n;i>=1;--i)
        {
            for(int d=2;d>=1;--d)
            {
                if(a[i][j][d]==0)continue;
                nx=i+dx[d];
                ny=j+dy[d];
                if(ff(change(i,j))==ff(change(nx,ny)))
                    continue;
                if(v[i][j]+v[nx][ny]>bv)
                {
                    bi=i;
                    bj=j;
                    bv=v[i][j]+v[nx][ny];
                    bd=d;
                }
            }
        }
    }
}

inline void printv()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            printf("%d ",v[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    in();
    init();
    find_room();
    break_wall();
    printf("%d\n%d\n%d\n",ans,maxv,bv);
    printf("%d %d ",bi,bj);
    if(bd==2)printf("N\n");
    else if(bd==1)printf("E\n");
    return 0;
}

inline void q1_pop(int &x,int &y)
{
    head++;
    x=qx1[head];
    y=qy1[head];
}

inline void q2_pop(int &x,int &y)
{
    head++;
    x=qx2[head];
    y=qy2[head];
}

inline void q_push(int x,int y)
{
    tail++;
    qx1[tail]=x;
    qx2[tail]=x;
    qy1[tail]=y;
    qy2[tail]=y;
}

int ff(int s)
{
    if(s!=f[s])
        f[s]=ff(f[s]);
    return f[s];
}

inline void connect(int i,int j)
{
    int fi=ff(i);
    int fj=ff(j);
    if(fi!=fj)
    {
        f[fj]=fi;
    }
}

inline void init()
{
    for(int i=n;i>=1;--i)
    {
        for(int j=1;j<=m;++j)
        {
            f[change(i,j)]=change(i,j);
        }
    }
}

inline void find_room()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(vis[i][j]==0)
            {
                dfs(i,j);
                ans++;
                maxv=max(nv,maxv);
            }
        }
    }
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
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&wall);
            set_wall(i,j,wall);
        }
    }
}
