#include <iostream>
#include <algorithm>
#include <cstdio>
//i had tried my best,but it eventually turned out that the mathod is not true
using namespace std;
int t,flag=1;
long long res=0;

struct node
{
    long long v;
    int r,dp;
}a[20005];

int cmp(node b,node c)
{
    return b.v<c.v;
}

int charu(int cur,int last)
{
    if(a[cur].r==0)
    {
        a[t].r=0;
        a[cur].r=t;
        return 0;
    }
    if((a[cur].v<a[t].v)||(a[cur].v==a[t].v&&a[cur].dp>a[t].dp))charu(a[cur].r,cur);
    else
    {
        a[t].r=cur;
        a[last].r=t;
    }
}

int solve(int cur)
{
    int next=a[flag].r;
    a[++t].v=a[flag].v+a[next].v;
    a[t].dp=max(a[flag].dp,a[next].dp)+1;
    res+=a[t].v;
    charu(a[next].r,next);
    flag=a[next].r;
}

int main()
{
    int n;
    scanf("%d",&n);
    t=n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i].v);
    sort(a,a+n,cmp);
    for(int i=1;i<n;i++)a[i].r=i+1;
    a[n].r=0;
    for(int i=1;i<n;i++)
        solve(flag);
    printf("%d\n",res);
    return 0;
}
