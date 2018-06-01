#include <iostream>

using namespace std;
int r[1001],e[1001];

int ff(int c)
{
    int f=c;
    while(r[f]!=f)
    {
        //int last=f;
        f=r[f];
        //r[last]=f;
    }
    return f;
}

int lianjie(int a,int b)
{
    int fa=ff(a),fb=ff(b);
    if(fa!=fb)
    {
        r[fa]=fb;
    }
}

int main()
{
    int n,m,a,b,res,out=0;
    char msg;
    cin>>n>>m;
    for(int i=1;i<=n;i++)r[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>msg>>a>>b;
        if(msg=='F')
        {
            lianjie(a,b);
        }
        else if(msg=='E')
        {
            if(e[a])lianjie(e[a],b);
            if(e[b])lianjie(e[b],a);
            e[a]=b;
            e[b]=a;
        }
    }
    for(int i=1;i<=n;i++)
    {
        res=0;
        for(int j=1;j<=n;j++)
        {
            if(ff(i)==ff(j))res++;
        }
        out=max(res,out);
    }
    cout<<out<<endl;
    return 0;
}
