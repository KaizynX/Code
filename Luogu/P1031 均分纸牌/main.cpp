#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100+5;

int n,a[maxn],sum,ave,ope[maxn],ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        sum+=a[i];
    }
    ave=sum/n;
    for(int i=1;i<=n;++i)
    {
        ope[i]=a[i]-ave;
        ope[i]+=ope[i-1];
        if(ope[i])ans++;
    }
    printf("%d\n",ans);
    return 0;
}
