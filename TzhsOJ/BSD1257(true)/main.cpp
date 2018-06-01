#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ba[1005];

struct cloud
{
    int x,y,l;
}yun[10005];

int cmp(cloud a,cloud b)
{
    return a.l<b.l;
}

int zhao(int son)
{
    int baba=son;
    while(ba[baba]!=baba)baba=ba[baba];
    return baba;
}

int main()
{
    int n,m,k,res=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)ba[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&yun[i].x,&yun[i].y,&yun[i].l);
        if(yun[i].x>yun[i].y)swap(yun[i].x,yun[i].y);
    }
    if(n==k)
    {
        printf("0\n");
        return 0;
    }
    if(n<k||k<n-m)
        {
        printf("No Answer\n");
        return 0;
    }
    sort(yun,yun+m,cmp);
    for(int i=0;i<m;i++)
    {
        int fx=zhao(yun[i].x),fy=zhao(yun[i].y);
        if(fx!=fy)
        {
            ba[fx]=fy;
            n--;
            res+=yun[i].l;
        }
        if(n==k)
        {
            printf("%d\n",res);
            return 0;
        }
    }
    return 0;
}
