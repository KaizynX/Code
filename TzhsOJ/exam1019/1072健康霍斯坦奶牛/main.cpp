#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxv=25+2;
const int maxg=15+2;

int v,g,vit[maxv],food[maxg][maxv],sum[maxg];
int minans,now[maxv],nsum,minsum=1000000;
bool ans[maxg],use[maxg];

inline bool pd()
{
    for(int i=1;i<=v;++i)
        if(now[i]<vit[i])
            return 0;
    return 1;
}

void dfs(int cur,int last)
{
    if(cur>minans)
        return;

    for(int i=last+1;i<=g;++i)
    {
        if(use[i])continue;
        use[i]=1;
        for(int j=1;j<=v;++j)
            now[j]+=food[i][j];
        nsum+=sum[i];

        if(pd())
        {
            if(cur<minans)
            {
                minans=cur;
                for(int k=1;k<=g;++k)
                    ans[k]=use[k];
                minsum=nsum;
            }
            else if(cur==minans)
            {
                if(nsum<minsum)
                {
                    for(int k=1;k<=g;++k)
                        ans[k]=use[k];
                    minsum=nsum;
                }
            }
        }
        else dfs(cur+1,i);

        for(int j=1;j<=v;++j)
            now[j]-=food[i][j];
        nsum-=sum[i];
        use[i]=0;
    }
}

int main()
{
    int i,j;
    scanf("%d",&v);
    for(i=1;i<=v;++i)
        scanf("%d",vit+i);
    scanf("%d",&g);
    for(i=1;i<=g;++i)
    {
        for(j=1;j<=v;++j)
        {
            scanf("%d",&food[i][j]);
            sum[i]+=food[i][j];
        }
    }
    minans=g;
    dfs(1,0);
    printf("%d ",minans);
    for(i=1;i<=g;++i)
        if(ans[i])printf("%d ",i);
    printf("\n");
    return 0;
}
