#include <iostream>
#include <cstdio>

using namespace std;

const int maxv=20000+5;
const int maxn=30+5;

int V,N;
int b[maxv],v;

int main()
{
    scanf("%d%d",&V,&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&v);
        for(int j=V;j>=v;--j)
        {
            b[j]=max(b[j],b[j-v]+v);
        }
    }
    printf("%d\n",V-b[V]);
    return 0;
}
