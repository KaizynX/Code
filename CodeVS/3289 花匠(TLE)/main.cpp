#include <iostream>
#include <cstdio>
using namespace std;
const int N=100000+5;
int n,ans,a[N],f[N];
bool b[N];//1 big , 0 small
//O(n^2) TLE 70
int main()
{
    int i,j,tmp,numa=1;
    scanf("%d%d",&n,&a[1]);
    for(i=1;i<n;++i)
    {
        scanf("%d",&tmp);
        if(tmp==a[numa])
            continue;
        a[++numa]=tmp;
    }
    if(a[1]>a[2])
        b[1]=1;
    else b[2]=1;
    f[1]=1;
    f[2]=2;
    for(i=3;i<=n;++i)
    {
        for(j=i-1;j>=1;--j)
        {
            if( (a[i]>a[j]&&b[j]==0) && f[j]+1>f[i] )
            {
                f[i]=f[j]+1;
                b[i]=1;
            }
            else if( (a[i]<a[j]&&b[j]==1) && f[j]+1>f[i] )
            {
                f[i]=f[j]+1;
                b[i]=0;
            }
        }
        if(f[i]>ans)
            ans=f[i];
    }
    cout<<ans<<endl;
    return 0;
}
