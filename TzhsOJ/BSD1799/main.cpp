#include <iostream>
#include <algorithm>
using namespace std;
int res=0;

struct tree
{
    int v,sonl,sonr;
}a[2005];

int cmp(tree x,tree y)
{
    return x.v<y.v;
}

int slove(int cur,int dp)
{
    if(a[cur].sonl!=0)slove(a[cur].sonl,dp+1);
    if(a[cur].sonr!=0)slove(a[cur].sonr,dp+1);
    if(a[cur].sonl==0&&a[cur].sonr==0)res+=a[cur].v*dp;
}

int main()
{
    int n,flag;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].sonl=0;
        a[i].sonr=0;
    }
    flag=n;
    for(int i=0;i<n-1;i++)
    {
        sort(a+1+2*i,a+n+1+i,cmp);
        a[++flag].v=a[2*i+1].v+a[2*i+2].v;
        a[flag].sonl=2*i+1;
        a[flag].sonr=2*i+2;
    }
    slove(flag,0);
    cout<<res<<endl;
    return 0;
}
