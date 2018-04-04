#include <iostream>

using namespace std;
int pre[20000];
int ffind(int x)
{
    int r=x;
    while(pre[r]!=r)
    {
        int last=r;
        r=pre[r];
        pre[last]=pre[r];//ÓÅ»¯
    }
    return r;
}
int join(int a,int b)
{
    int fa=ffind(a),fb=ffind(b);
    if(fa!=fb)pre[fa]=fb;
}
int main()
{
    int x,m,n;
    cin>>x>>m>>n;
    for(int i=1;i<=x;i++)pre[i]=i;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        join(a,b);
    }
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(ffind(a)==ffind(b))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
