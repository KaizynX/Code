#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=30000+5;
int w,n,ans,num,nw,a[maxn],use[maxn];
int main()
{
    scanf("%d%d",&w,&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    sort(a+1,a+1+n);
    for(int i=n;i>=1;--i)
    {
        if(use[i])continue;
        nw=w-a[i];
        use[i]=1;
        ans++;
        for(int j=i-1;j>=1;--j)
        {
            if(use[j])continue;
            if(a[j]<=nw)
            {
                use[j]=1;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
