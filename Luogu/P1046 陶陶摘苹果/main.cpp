#include <iostream>
#include <cstdio>
using namespace std;
int a[15],b,ans;
int main()
{
    for(int i=1;i<=10;++i)
        scanf("%d",a+i);
    scanf("%d",&b);
    b+=30;
    for(int i=1;i<=10;++i)
    {
        if(b>=a[i])
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
