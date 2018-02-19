#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxt = 10000+5;
const int Maxn = 1000000+5;

int T,n,ans;
int a[10],res[10];

void change(int n)// 364 to 4 6 3
{
    memset(a,0,sizeof a);
    int cur=1;
    while(n)
    {
        a[cur]=n%10;
        if(a[cur]>ans)ans=a[cur];
        n/=10;
        cur++;
    }
}

void solve()
{
    memset(res,0,sizeof res);
    for(int i=1;i<=ans;++i)
    {
        for(int j=8;j>=1;--j)
        {
            res[i]*=10;
            if(a[j]>0)
            {
                a[j]--;
                res[i]+=1;
            }
        }
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        change(n);
        printf("%d\n",ans);
        solve();
        for(int i=ans;i>1;--i)
        {
            printf("%d ",res[i]);
        }
        printf("%d\n",res[1]);
    }
    return 0;
}
