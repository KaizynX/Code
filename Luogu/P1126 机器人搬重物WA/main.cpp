#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=50+5;
const int maxq=10000*2+5;
const int INF=0x7fffffff;
/**    0
    1 mid  3
       2     **/
int n,m,bx,by,ex,ey,dir,ans=INF;
int a[maxn][maxn],walk[4][2]={-1,0,0,-1,1,0,0,1};
bool vis[maxn][maxn];
int x,y,d,t;
int qx[maxq],qy[maxq],qd[maxq],qt[maxq];
int hx,tx,hy,ty,hd,td,ht,tt;

inline void read();
inline void q_out();
inline void q_in(int x,int y,int d,int t);

void bfs()
{
    int nx,ny;
    while(hx<=tx)
    {
        q_out();
        if(x==ex && y==ey)
        {
            if(t<ans)
            {
                ans=t;
            }
            continue;
        }
        if(t>ans)
            continue;

        vis[x][y]=1;
        for(int i=1;i<=3;++i)//
        {
            nx=x+i*walk[d][0];
            ny=y+i*walk[d][1];
            if(a[nx][ny])
                break;
            if(nx<=0 || nx>=n || ny<=0 || ny>=m)
                break;
            if(vis[nx][ny])
                break;//continue;
            q_in(nx,ny,d,t+1);
        }
        for(int i=1;i<=3;++i)//left
        {
            nx=x+i*walk[(d+1)%4][0];
            ny=y+i*walk[(d+1)%4][1];
            if(a[nx][ny])
                break;
            if(nx<=0 || nx>=n || ny<=0 || ny>=m)
                break;
            if(vis[nx][ny])
                break;//continue;
            q_in(nx,ny,(d+1)%4,t+2);
        }
        for(int i=1;i<=3;++i)//right
        {
            nx=x+i*walk[(d-1+4)%4][0];
            ny=y+i*walk[(d-1+4)%4][1];
            if(a[nx][ny])
                break;
            if(nx<=0 || nx>=n || ny<=0 || ny>=m)
                break;
            if(vis[nx][ny])
                break;//continue;
            q_in(nx,ny,(d-1+4)%4,t+2);
        }
        for(int i=1;i<=3;++i)//back
        {
            nx=x+i*walk[(d+2)%4][0];
            ny=y+i*walk[(d+2)%4][1];
            if(a[nx][ny])
                break;
            if(nx<=0 || nx>=n || ny<=0 || ny>=m)
                break;
            if(vis[nx][ny])
                break;//continue;
            q_in(nx,ny,(d+2)%4,t+3);
        }

        vis[x][y]=0;
    }
}

int main()
{
    //freopen("1126.in","r",stdin);//
    read();
    if(a[ex][ey]==1)
    {
        printf("-1\n");
        return 0;
    }
    bfs();
    if(ans==INF)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}

inline void read()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
            {
                a[i-1][j]=1;
                a[i][j-1]=1;
                a[i-1][j-1]=1;
            }
        }
    }
    scanf("%d%d%d%d",&bx,&by,&ex,&ey);
    char c;
    cin>>c;
    if(c=='N')dir=0;
    else if(c=='W')dir=1;
    else if(c=='S')dir=2;
    else if(c=='E')dir=3;
    q_in(bx,by,dir,0);
}

inline void q_out()
{
    x=qx[hx];hx++;
    y=qy[hy];hy++;
    d=qd[hd];hd++;
    t=qt[ht];ht++;
}

inline void q_in(int x,int y,int d,int t)
{
    qx[tx]=x;tx++;
    qy[ty]=y;ty++;
    qd[td]=d;td++;
    qt[tt]=t;tt++;
}
