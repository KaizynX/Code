#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=20+5;
const int maxl=1000;

int n,use[maxn],ans;
char a[maxn][maxl];
int co[maxn][maxn];

int pd(int s1,int s2)
{
    bool flag=1;
    int i,j;
    for(i=strlen(a[s1])-1;i>=1;--i)
    {
        flag=1;
        for(j=i;j<=strlen(a[s1])-1;++j)
        {
            if(a[s1][j]!=a[s2][j-i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            int res=strlen(a[s2])-(strlen(a[s1])-i);
            return res;
        }
    }
    return 0;
}

void dfs(int last,int len)
{
    ans=max(len,ans);
    for(int i=1;i<=n;++i)
    {
        if(co[last][i]==0 || use[i]>=2)
            continue;

        use[i]++;
        dfs(i,len+co[last][i]);
        use[i]--;
    }
}

int main()
{
    int i,j;
    char head;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            co[i][j]=pd(i,j);
        }
    }
    cin>>head;
    for(i=1;i<=n;++i)
    {
        if(a[i][0]==head)
        {
            use[i]++;
            dfs(i,strlen(a[i]));
            use[i]--;
        }
    }
    printf("%d\n",ans);
    return 0;
}

