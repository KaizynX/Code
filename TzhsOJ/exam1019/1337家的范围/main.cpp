#include <iostream>
#include <cstdio>

using namespace std;
const int maxn=250+5;

int n,a[maxn][maxn],num[maxn];
bool m[maxn][maxn];

inline int min3(int a,int b,int c)
{
    return min(min(a,b),c);
}

int main()
{
    int i,j;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            cin>>c;
            if(c=='1')
                m[i][j]=1;
        }
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(m[i][j])
            {
                a[i][j]=min3(a[i-1][j],a[i][j-1],a[i-1][j-1])+1;
                num[a[i][j]]++;
            }
        }
    }
    for(i=n;i>2;--i)
        num[i-1]+=num[i];
    for(i=2;i<=n;++i)
    {
        if(num[i])
            printf("%d %d\n",i,num[i]);
    }
    return 0;
}
