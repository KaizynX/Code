#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=30+2;

int n,m[maxn][maxn],posx,posy;
bool vis[maxn][maxn];

bool bfs(int x,int y)
{
    if(vis[x][y])
        return 1;
    if(x<1 || x>n || y<1 || y>n)
        return 0;
    if(m[x][y]!=0)
        return 1;
    bool res;
    vis[x][y]=1;
    res=(bfs(x+1,y)&&bfs(x-1,y)&&bfs(x,y-1)&&bfs(x,y+1));
    vis[x][y]=0;
    if(res && (x>posx||x==posx&&y>=posy))
        m[x][y]=2;
    return res;
}

inline void read()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&m[i][j]);
        }
    }
}

inline void print()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

inline void solve()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(m[i][j]==0)
            {
                posx=i,posy=j;
                bfs(i,j);
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    read();
    solve();
    print();
    return 0;
}
