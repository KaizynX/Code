#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m,ku[100],a,cur=0,flag,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<100;i++)ku[i]=-1;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a);
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(ku[j]==a)flag=1;
        }
        if(!flag)
        {
            ans++;
            ku[cur++]=a;
            if(cur>=n)cur=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}
