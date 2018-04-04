#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=30+5;
const int maxq=27000+5;
const int dx[]={0,0,0,0,1,-1};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={1,-1,0,0,0,0};

int L,R,C,bx,by,bz,ex,ey,ez;
int a[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int head,tail,qx[maxq],qy[maxq],qz[maxq],qt[maxq];

inline bool in();
inline void solve();

bool bfs()
{
    int nx,ny,nz,nt;
    tail++;
    qx[tail]=bx;
    qy[tail]=by;
    qz[tail]=bz;
    qt[tail]=0;
    vis[bx][by][bz]=1;
    while(head<tail)
    {
        head++;
        for(int d=0;d<6;++d)
        {
            nx=qx[head]+dx[d];
            ny=qy[head]+dy[d];
            nz=qz[head]+dz[d];
            nt=qt[head]+1;
            if(nx==ex && ny==ey && nz==ez)
            {
                printf("Escaped in %d minute(s).\n",nt);
                return 1;
            }
            if(a[nx][ny][nz]==0 || vis[nx][ny][nz]==1)
                continue;
            vis[nx][ny][nz]=1;
            tail++;
            qx[tail]=nx;
            qy[tail]=ny;
            qz[tail]=nz;
            qt[tail]=nt;
        }
    }
    return 0;
}

int main()
{
    solve();
    return 0;
}

inline void solve()
{
    while(in())
    {
        memset(vis,0,sizeof vis);
        head=0;
        tail=0;
        if(bfs()==0)
            printf("Trapped!\n");
    }
}

inline bool in()
{
    char c;
    scanf("%d%d%d",&L,&R,&C);
    if(L==0 && R==0 && C==0)return 0;
    memset(a,0,sizeof a);
    for(int i=1;i<=L;++i)
    {
        for(int j=1;j<=R;++j)
        {
            for(int k=1;k<=C;++k)
            {
                cin>>c;
                if(c=='.')a[j][k][i]=1;
                else if(c=='#')a[j][k][i]=0;
                else if(c=='S')
                {
                    bz=i;
                    bx=j;
                    by=k;
                    a[i][j][k]=1;
                }
                else if(c=='E')
                {
                    ez=i;
                    ex=j;
                    ey=k;
                    a[i][j][k]=1;
                }
            }
        }
    }
    return 1;
}
