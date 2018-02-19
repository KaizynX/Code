#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct ren
{
    int num,fen;
}a[5005];

int cmp(ren a1,ren a2)
{
    if(a1.fen>a2.fen)return 1;
    else if(a1.fen==a2.fen)return a1.num<a2.num;
    else return 0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].num,&a[i].fen);
    }
    sort(a,a+n,cmp);

    int m1,ans;
    m1=m*1.5;
    ans=a[m1-1].fen;
    while(a[m1].fen==a[m1-1].fen)
    {
        m1++;
    }
    printf("%d %d\n",ans,m1);
    for(int i=0;i<m1;i++)printf("%d %d\n",a[i].num,a[i].fen);
    return 0;
}
