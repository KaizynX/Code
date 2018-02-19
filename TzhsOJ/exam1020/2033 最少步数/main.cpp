#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+5;
const int maxq=100000+5;
int bx,by,x,y,s;
int qx[maxq],qy[maxq],qs[maxq],head,tail;
int dx[12]={-2,-2,-1,-1,1,1,2,2,2,2,-2,-2};
int dy[12]={1,-1,2,-2,2,-1,1,-1,2,-2,2,-2};
bool vis[maxn][maxn];
inline void init();
inline void solve();
inline void q_push(int x,int y,int s);
inline void q_pop();

void bfs()
{
    int nx,ny;
    while(head<tail)
    {
        q_pop();
        for(int i=0;i<12;++i)
        {
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx==1 && ny==1)
            {
                printf("%d\n",s+1);
                return;
            }
            if(vis[nx][ny])continue;
            if(nx<1 || nx>100 || ny<1 || ny>100)continue;
            vis[nx][ny]=1;
            q_push(nx,ny,s+1);
        }
    }
}

int main()
{
    solve();
    solve();
    return 0;
}

inline void solve()
{
    scanf("%d%d",&bx,&by);
    if(bx==1 && by==1)
    {
        printf("0\n");
        return;
    }
    init();
    bfs();
}

inline void init()
{
    memset(qx,0,sizeof qx);
    memset(qy,0,sizeof qy);
    memset(vis,0,sizeof vis);
    head=0;tail=0;
    q_push(bx,by,0);
}

inline void q_push(int x,int y,int s)
{
    qx[tail]=x;
    qy[tail]=y;
    qs[tail]=s;
    tail++;
}
inline void q_pop()
{
    x=qx[head];
    y=qy[head];
    s=qs[head];
    head++;
}
