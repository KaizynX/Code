#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100+5;

int c,r,ans;
int a[maxn][maxn],s[maxn][maxn];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

inline void in();
inline void solve();

int bfs(int x,int y)
{
    int next=0,nx,ny;
    for(int i=0;i<4;++i)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<1 || nx>c || ny<1 || ny>r)
            continue;
        if(a[x][y]>a[nx][ny])
        {
            if(s[nx][ny]>1)
                next=max(next,s[nx][ny]);
            else
                next=max(next,bfs(nx,ny));
        }
    }
    s[x][y]=next+1;
    return s[x][y];
}

int main()
{
    in();
    solve();
    printf("%d\n",ans);
    return 0;
}

inline void in()
{
    scanf("%d%d",&c,&r);
    for(int i=1;i<=c;++i)
    {
        for(int j=1;j<=r;++j)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=1;
        }
    }
}

inline void solve()
{
    for(int i=1;i<=c;++i)
    {
        for(int j=1;j<=r;++j)
        {
            if(s[i][j]>1)continue;
            bfs(i,j);
            ans=max(ans,s[i][j]);
        }
    }
}
