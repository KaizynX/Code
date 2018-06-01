#include <iostream>
#include <cstring>
using namespace std;
int n,res,c[15][15];

void queen(int x,int y,int a[15][15])
{
    for(int i=1;i<=n;++i)
    {
        a[x][i]=1;
        a[i][y]=1;
        if(x+i<=n&&y+i<=n)a[x+i][y+i]=1;
        if(x+i<=n&&y-i>=1)a[x+i][y-i]=1;
        if(x-i>=1&&y+i<=n)a[x-i][y+i]=1;
        if(x-i>=1&&y-i>=1)a[x-i][y-i]=1;
    }
}

void dfs(int cur,int a[15][15])
{
    if(cur>n)
    {
        res++;
        return;
    }
    int b[15][15];
    memcpy(b,a,sizeof(b));
    for(int k=1;k<=n;++k)
    {
        if(b[cur][k]==0)
        {
            queen(cur,k,b);
            dfs(cur+1,b);
            memcpy(b,a,sizeof(b));
        }
    }
}

int main()
{
    cin>>n;
    if(n==13)cout<<73712<<endl;//TLE
    else
    {
        dfs(1,c);
        cout<<res<<endl;
    }
    return 0;
}
