#include <iostream>
#include <cstdio>
//#include <cmath>
using namespace std;
int pre[30001],before[30001],total[30001];

int zhao(int son)
{
    if(son!=pre[son])
    {
        int ba=zhao(pre[son]);
        before[son]+=before[pre[son]];
        pre[son]=ba;
    }
    return pre[son];
}

int main()
{
    int T;
    char c;
    int a,b;
    scanf("%d",&T);
    for(int i=1;i<=30000;i++)
    {
        pre[i]=i;
        total[i]=1;
    }
    int t=T;
    for(int i=0;i<t;i++)
    {
        scanf("%s%d%d",&c,&a,&b);
        int fa=zhao(a),fb=zhao(b);
        if(c=='M')
        {
            if(fa!=fb)
            {
                pre[fa]=fb;
                before[fa]=total[fb];
                total[fb]+=total[fa];
            }
        }
        else
        {
            if(fa!=fb)printf("-1");
            else
            {
                //printf("%d\n",abs(before[a]-before[b])-1);
                int ans=before[a]-before[b];
                if(ans<0)printf("%d\n",-ans-1);
                else printf("%d\n",ans-1);
            }
        }
    }
    return 0;
}
