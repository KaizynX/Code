#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const char ans[]="yizhong";
const int maxn=100+5;
char a[maxn][maxn],res[maxn][maxn];
int n;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
bool vis[maxn][maxn];

inline void read();
inline void init();
inline void solve();
inline void print();

inline bool pd(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n)
        return 0;
    if(vis[x][y])
        return 0;
    return 1;
}

bool bfs(int x,int y,int d,int i)
{
    if(i>=7)return 1;
    if(pd(x,y)==0)return 0;
    if(a[x][y]==ans[i])
    {
        int nx,ny;
        nx=x+dx[d];
        ny=y+dy[d];
        if(bfs(nx,ny,d,i+1))
        {
            res[x][y]=ans[i];
            return 1;
        }
    }
    return 0;
}



int main()
{
    read();
    init();
    solve();
    print();
    return 0;
}

inline void read()
{
    char c;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
        }
    }
}

inline void init()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            res[i][j]='*';
        }
    }
}

inline void solve()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]!='y')continue;
            for(int d=0;d<8;++d)
                bfs(i,j,d,0);
        }
    }
}

inline void print()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<res[i][j];
        }
        cout<<endl;
    }
}
/**
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg
**/
