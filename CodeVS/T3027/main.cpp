#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int a,b,v;
}x[1001];

int cmp(node x1,node x2)
{
    return x1.a<x2.a;
}

int main()
{
    int n,maxk=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i].a>>x[i].b>>x[i].v;
        if(x[i].a>x[i].b)swap(x[i].a,x[i].b);
    }
    sort(x,x+n,cmp);
    for(int i=1;i<n;i++)
    {
        maxk=0;
        for(int j=0;j<i;j++)
        {
            if(x[j].a>=x[i].b||x[j].b<=x[i].a)
            {
                maxk=max(maxk,x[j].v);
            }
        }
        x[i].v+=maxk;
        ans=max(ans,x[i].v);
    }
    cout<<ans<<endl;
    return 0;
}
