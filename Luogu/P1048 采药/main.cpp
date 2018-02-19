#include <iostream>
#include <cstdio>

using namespace std;

const int maxt=1000+5;
const int maxm=100+5;

int T,M;
int b[maxt],t[maxm],v[maxm];

int main()
{
    scanf("%d%d",&T,&M);
    for(int i=1;i<=M;++i)
    {
        scanf("%d%d",t+i,v+i);
    }
    for(int i=1;i<=M;++i)
    {
        for(int j=T;j>=t[i];--j)
        {
            b[j]=max(b[j],b[j-t[i]]+v[i]);
        }
    }
    printf("%d",b[T]);
    return 0;
}
