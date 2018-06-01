#include <iostream>
#include <algorithm>
using namespace std;

struct jiqi
{
    int a;
    int b;
    int c;
};
jiqi x[100001];

int pre[100001],ans;

bool cmp(jiqi x1,jiqi x2)
{
    return x1.c<x2.c;
}

int ffind(int y)
{
    int r=y;
    while(pre[r]!=r)r=pre[r];
}

int join(int a,int b)
{
    int flag=0;
    int fa=ffind(a),fb=ffind(b);
    if(fa!=fb)
    {
        pre[fa]=fb;
        flag=1;
    }
    return flag;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>x[i].a>>x[i].b>>x[i].c;
    for(int i=1;i<=n;i++)pre[i]=i;
    sort(x+1,x+m+1,cmp);
    int x1,x2;
    for(int i=1;i<=m;i++)
    {
        x1=x[i].a;
        x2=x[i].b;
        if(join(x1,x2))ans+=x[i].c;
    }
    cout<<ans<<endl;
    return 0;
}
