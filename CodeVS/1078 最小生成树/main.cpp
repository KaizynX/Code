#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
int N,farm[maxn][maxn],sum=0,f[maxn],ans;
struct rode
{
    int x,y,l;
}r[maxn*maxn/2];

bool cmp(rode a,rode b)
{
    return a.l<b.l;
}

int ff(int s)
{
    int fa=f[s];
    if(fa!=s)fa=ff(fa);
    f[s]=fa;
    return fa;
}

int main()
{
    int i,j,a,now=0;
    scanf("%d",&N);
    for(i=1;i<=N;++i)
    {
        for(j=1;j<=N;++j)
        {
            scanf("%d",&a);
            if(i>=j)continue;
            r[sum].x=i;
            r[sum].y=j;
            r[sum].l=a;
            ++sum;
        }
        f[i]=i;
    }
    sort(r,r+sum,cmp);
    for(i=0;i<sum;++i)
    {
        int x=r[i].x,y=r[i].y;
        int fx=ff(x),fy=ff(y);
        if(fx!=fy)
        {
            f[fx]=fy;
            now++;
            ans+=r[i].l;
        }
        if(now>=N-1)break;
    }
    printf("%d\n",ans);
    return 0;
}
