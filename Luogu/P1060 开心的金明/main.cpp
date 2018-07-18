#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=30000+5;
const int maxm=25+5;

int n,m;
int b[maxn],v[maxm],w[maxm],a[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",v+i,w+i);
        a[i]=v[i]*w[i];
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=n;j>=v[i];--j)
        {
            b[j]=max(b[j],b[j-v[i]]+a[i]);
        }
    }
    printf("%d\n",b[n]);
    return 0;
}
