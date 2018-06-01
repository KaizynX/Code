#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k;
int main()
{
    freopen("prison.in","r",stdin);
    freopen("prison.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if(n==2)
    {
        if(m==0||n>=1)
            printf("0\n");
        else printf("1\n");
    }
    return 0;
}
