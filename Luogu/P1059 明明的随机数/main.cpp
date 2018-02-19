#include <iostream>
#include <cstdio>
using namespace std;
const int maxm=1000+5;

int n,t[maxm],sum;

int main()
{
    int a;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a);
        t[a]++;
    }
    for(int i=1;i<=1000;++i)
    {
        if(t[i])sum++;
    }
    printf("%d\n",sum);
    for(int i=1;i<=1000;++i)
    {
        if(t[i])
            printf("%d ",i);
    }
    putchar('\n');
    return 0;
}
