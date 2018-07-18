#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=5000+5;

int n,m;
struct node
{
    int f,v;
    bool operator < (const node b)const
    {
        if(v>b.v)return 1;
        else if(v<b.v)return 0;
        return f<b.f;
    }
}a[maxn];

int main()
{
    int r,d,sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i].f,&a[i].v);
    }
    sort(a+1,a+1+n);
    r=m*1.5;
    d=a[r].v;
    for(int i=1;i<=n;++i)
    {
        if(a[i].v>=d)
            sum++;
        else break;
    }
    printf("%d %d\n",d,sum);
    for(int i=1;i<=sum;++i)
        printf("%d %d\n",a[i].f,a[i].v);
    return 0;
}
