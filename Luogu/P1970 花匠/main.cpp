#include <iostream>
#include <cstdio>
using namespace std;
const int N=100000+5;
int n,a[N],flag,ans=1;
//don't know why
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d",a+i);
    for(i=1;i<=n-1;++i)
        if(a[i]<a[i+1]&&flag!=1)
        {
            ans++;
            flag=1;
        }
        else if(a[i]>a[i+1]&&flag!=2)
        {
            ans++;
            flag=2;
        }
    printf("%d\n",ans);
    return 0;
}
