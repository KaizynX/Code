#include <iostream>
#include <algorithm>
using namespace std;
int pre[10001];

struct node
{
    int u,v,c;
}a[10001];

int cmp(node a,node b)
{
    return a.c<b.c;
}

int found(int son)
{
    int father=son;
    if(pre[son]!=son)father=found(pre[son]);
    pre[son]=father;
    return father;
}

int main()
{
    int n,m,res1=0,flag;
    cin>>n>>m;
    for(int i=1;i<=n;i++)pre[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].c;
        if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
    }
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++)
    {
        int fu=found(a[i].u),fv=found(a[i].v);
        if(fu!=fv)
        {
            pre[fu]=fv;
            res1++;
            flag=i;
        }
        if(res1==n-1)break;
    }
    cout<<res1<<" "<<a[flag].c<<endl;
    return 0;
}
