#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int ba[100005];

struct luxian
{
    int x,y;
    double s;
}lu[100005];

int cmp(luxian a,luxian b)
{
    return a.s<b.s;
}

int zhao(int son)
{
    int fa=son;
    while(ba[fa]!=fa)fa=ba[fa];
    return fa;
}

int main()
{
    double S,ans=0;
    int n,i=0,num=0;
    scanf("%lf%d",&S,&n);
    for(int j=1;j<=n;j++)ba[j]=j;
    while(scanf("%d%d%lf",&lu[i].x,&lu[i].y,&lu[i].s)==3)
    {
        i++;
    }
    sort(lu,lu+i,cmp);
    for(int j=0;j<i;j++)
    {
        int fx=zhao(lu[j].x),fy=zhao(lu[j].y);
        if(fx!=fy)
        {
            ba[fx]=fy;
            ans+=lu[j].s;
            num++;
        }
        if(num==n-1)break;
    }
    if(ans>S||num<n-1)printf("Impossible\n");
    else printf("Need %.2lf miles of cable\n",ans);
    return 0;
}
