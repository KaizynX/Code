#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=400+5;
const int maxq=200000+5;

int a[maxn][maxn],n,m,bx,by;
int wx[8]={-1,-2,-2,-1,1,2,2,1};
int wy[8]={-2,-1,1,2,2,1,-1,-2};
int qx[maxq],qy[maxq],qt[maxq],head,tail;

inline void q_push(int x,int y,int t);
inline void q_pop(int &x,int &y,int &t);
inline void print();

void bfs()
{
    int x,y,t;
    while(head<tail)
    {
        q_pop(x,y,t);
        int nx,ny;
        for(int i=0;i<8;++i)
        {
            nx=x+wx[i];
            ny=y+wy[i];
            if(nx<1 || nx>n || ny<1 || ny>m)
                continue;
            if(a[nx][ny]==-1)
            {
                q_push(nx,ny,t+1);
                a[nx][ny]=t+1;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&bx,&by);
    memset(a,-1,sizeof a);
    q_push(bx,by,0);
    a[bx][by]=0;
    bfs();
    print();
    return 0;
}

inline void print()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            printf("%-5d",a[i][j]);
        }
        printf("\n");
    }
}

inline void q_push(int x,int y,int t)
{
    qx[tail]=x;
    qy[tail]=y;
    qt[tail]=t;
    tail++;
}

inline void q_pop(int &x,int &y,int &t)
{
    x=qx[head];
    y=qy[head];
    t=qt[head];
    head++;
}
