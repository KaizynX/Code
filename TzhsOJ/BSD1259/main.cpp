#include <iostream>
#include <cstdio>
//codevs 2540  TLE
using namespace std;
int tou[30009],wei[30009];
int finaltou[30009],finalwei[30009];

int ftou(int son)
{
    int ba=finaltou[son];
    while(ba!=tou[ba])ba=tou[ba];
    int i;
    while(tou[son]!=ba)
    {
        i=tou[son];
        finaltou[son]=ba;
        son=i;
    }
    return ba;
}

int fwei(int ba)
{
    int son=finalwei[ba];
    while(wei[son]!=son)son=wei[son];
    int i;
    while(wei[ba]!=son)
    {
        i=wei[ba];
        finalwei[ba]=son;
        ba=i;
    }
    return son;
}

void lianjie(int a,int b)
{
    int fa=ftou(a),fb=ftou(b);
    int sa=fwei(a),sb=fwei(b);
    if(fa!=fb)
    {
        tou[fa]=sb;
        wei[sb]=fa;
    }
}

int ans(int a,int b)
{
    int sa=a,ca=0;
    while(tou[sa]!=sa)
    {
        sa=tou[sa];
        ca++;
    }
    int sb=b,cb=0;
    while(tou[sb]!=sb)
    {
        sb=tou[sb];
        cb++;
    }
    if(ca>=cb)return ca-cb-1;
    else return cb-ca-1;
}

int main()
{
    int T,a,b;
    char c;
    scanf("%d",&T);
    for(int i=1;i<=30000;i++)
    {
        tou[i]=i;
        wei[i]=i;
        finaltou[i]=i;
        finalwei[i]=i;
    }
    for(int i=0;i<T;i++)
    {
        scanf("%s %d %d",&c,&a,&b);
        if(c=='M')
        {
            lianjie(a,b);
        }
        else
        {
            int fa=ftou(a),fb=ftou(b);
            if(fa!=fb)printf("%d\n",-1);
            else printf("%d\n",ans(a,b));
        }
    }
    return 0;
}
