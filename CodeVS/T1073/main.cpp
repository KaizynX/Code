#include <iostream>

using namespace std;
int pre[5009];

int ffind(int x)
{
    int r=x;
    while(pre[r]!=r)
    {
        r=pre[r];
    }
    return r;
}

int join(int a,int b)
{
    int fa=ffind(a),fb=ffind(b);
    if(fa!=fb)
    {
        pre[fa]=fb;
    }
    return 0;
}

int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)pre[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        join(a,b);
    }
    for(int i=1;i<=p;i++)
    {
        int p1,p2;
        cin>>p1>>p2;
        if(ffind(p1)==ffind(p2))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
