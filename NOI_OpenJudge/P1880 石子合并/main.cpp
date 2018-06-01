#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=300+5;
const int INF = 1<<30;

int fmax[maxn][maxn],fmin[maxn][maxn],sum[maxn][maxn];
int a[maxn],n,minc=INF,maxc=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        a[i+n]=a[i];
        a[i+n*2]=a[i];
    }
    for(int i=1;i<=3*n;++i)
    {
        for(int j=i;j<=3*n;++j)
        {
            sum[i][j]=sum[i][j-1]+a[j];
        }
    }
    for(int l=2;l<=n;++l)
    {
        for(int i=1;i<=3*n-l+1;++i)
        {
            int j=i+l-1;
            fmin[i][j]=INF;
            for(int k=i;k<=j-1;++k)
            {
                fmax[i][j]=max(fmax[i][j],fmax[i][k]+fmax[k+1][j]+sum[i][j]);
                fmin[i][j]=min(fmin[i][j],fmin[i][k]+fmin[k+1][j]+sum[i][j]);
            }
        }
    }
    for(int i=1;i<=2*n+1;++i)
    {
        minc=min(minc,fmin[i][i+n-1]);
        maxc=max(maxc,fmax[i][i+n-1]);
    }
    printf("%d\n%d\n",minc,maxc);
    return 0;
}
