#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int baba[30009],depth[30009],length[30009];

int zhao(int son)
{
    if(son!=baba[son])
    {
        int ba=zhao(baba[son]);
        depth[son]+=depth[baba[son]];
        baba[son]=ba;
    }
    return baba[son];
}

int main()
{
    int T,x,y;
    char a;
    for(int i=1;i<=30000;i++)
    {
        baba[i]=i;
        length[i]=1;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%d%d",&a,&x,&y);
        int fx=zhao(x),fy=zhao(y);
        if(a=='M')
        {
            baba[fx]=fy;
            depth[fx]=length[fy];
            length[fy]+=length[fx];
        }
        else
        {
            if(fx!=fy)printf("%d\n",-1);
            else printf("%d\n",abs(depth[x]-depth[y])-1);
        }
    }
    return 0;
}
