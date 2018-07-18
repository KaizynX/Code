#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=3200+5;
const int maxm=60+5;

int n,m;
int b[maxn][maxm];
int v[maxm][4],a[maxm][4];
int flag[maxm];

// [][0] 0
// [][1] 0+1
// [][2] 0+2
// [][3] 0+1+2

int main()
{
    scanf("%d%d",&n,&m);
    int nv,nw,nq;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&nv,&nw,&nq);
        if(nq==0)
        {
            v[i][0]=nv/10;
            a[i][0]=v[i][0]*nw;
        }
        if(nq!=0)
        {
            v[nq][++flag[nq]]=v[nq][0]+nv/10;
            a[nq][flag[nq]]=a[nq][0]+nv/10*nw;
            if(flag[nq]==2)
            {
                flag[nq]++;
                v[nq][3]=v[nq][1]+v[nq][2]-v[nq][0];
                a[nq][3]=a[nq][1]+a[nq][2]-a[nq][0];
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=n/10;j>=0;--j)
        {
            b[j][i]=b[j][i-1];
            for(int k=0;k<=flag[i];++k)
            {
                if(j>=v[i][k])
                {
                    b[j][i]=max(b[j][i],b[j-v[i][k]][i-1]+a[i][k]);
                }
            }
        }
    }
    printf("%d\n",b[n/10][m]*10);
    return 0;
}
