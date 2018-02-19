#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
//codevs”–∂æ∞°∞°∞°
struct jiqi
{
    int a,b,c;
}x[100001];

int pre[100001];

int cmp(jiqi x1,jiqi x2)
{
    return x1.c<x2.c;
}

int ffind(int y)
{
    int r=y;
    while(pre[r]!=r)r=pre[r];
    int i=y,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
}

int join(int a,int b)
{
    int fa=ffind(a),fb=ffind(b);
    if(fa!=fb)
    {
        pre[fa]=fb;
    }
}

int main()
{
    int n,m,cishu=0;
    long long res=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
    for(int i=1;i<=n;i++)pre[i]=i;
    sort(x+1,x+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(ffind(x[i].a)!=ffind(x[i].b))
        {
            join(x[i].a,x[i].b);
            res+=x[i].c;
            cishu++;
            if(cishu==n-1)break;
        }
    }
    printf("%lld",res);
    return 0;
}
