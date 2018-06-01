#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=13+2;
int n,res[maxn],ans,cnt;
bool check[3][maxn*2];
/**
   _____>check[0]
  /
10101--->check[1]
01110
11111
01110
10101--->check[2]
**/

inline bool pd(int x,int y)
{
    return check[0][y]==0&&check[1][x+y]==0&&check[2][x-y+2*maxn]==0;
}

inline void print()
{
    for(int i=1;i<n;++i)
        printf("%d ",res[i]);
    printf("%d\n",res[n]);
}

void dfs(int cur)
{
    if(cur>n)
    {
        ans++;
        if(cnt>=3)return;
        print();
        cnt++;
    }

    int x,y;
    for(int i=1;i<=n;++i)
    {
        if(pd(cur,i))
        {
            x=cur,y=i;

            check[0][y]=1;
            check[1][x+y]=1;
            check[2][x-y+2*maxn]=1;

            res[cur]=i;
            dfs(cur+1);

            check[0][y]=0;
            check[1][x+y]=0;
            check[2][x-y+2*maxn]=0;
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
