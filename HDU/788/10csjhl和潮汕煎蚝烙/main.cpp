#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxa = 10+5;

int T,ans;
int a[6];

void dfs(int cur,int sum)
{
    if(cur>5)
    {
        if(sum==24)ans++;
        return;
    }
    dfs(cur+1,sum+a[cur]);
    dfs(cur+1,sum-a[cur]);
}

int main()
{
    int b;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        memset(a,0,sizeof a);
        for(int i=1;i<=5;++i)
        {
            scanf("%d",a+i);
        }
        dfs(2,a[1]);
        printf("%d\n",ans);
    }
    return 0;
}
