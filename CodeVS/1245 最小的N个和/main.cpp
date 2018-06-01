#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005;
struct num
{
    int v,ai,bi;
    bool operator < (const num &b)const
    {
        return v>b.v;//small
    }
    void operator = (const num &b)
    {
        v=b.v;
        ai=b.ai;
        bi=b.bi;
    }
}c;
priority_queue <num>q;
int n,a[maxn],b[maxn],flag[maxn];
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",a+i);
    for(i=0;i<n;++i)
        scanf("%d",b+i);
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;++i)
    {
        c.ai=i;
        c.bi=0;
        c.v=a[i]+b[0];
        q.push(c);
    }
    for(i=0;i<n;++i)
    {
        c=q.top();
        q.pop();
        printf("%d ",c.v);
        c.bi++;
        if(c.bi>=n)continue;
        c.v=a[c.ai]+b[c.bi];
        q.push(c);
    }
    printf("\n");
    return 0;
}
