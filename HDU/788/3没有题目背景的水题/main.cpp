#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 5000+5;
const int Maxt = 10+5;

int T,n,k;
int a[Maxn],sum[Maxn];

int main()
{
    int now,flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",a+i);
            sum[i]=a[i]+sum[i-1];
        }
        flag=0;
        for(int l=1;l<=n;++l)
        {
            if(flag)break;
            for(int r=l;r<=n;++r)
            {
                now=sum[r]-sum[l-1];
                if(now==k)
                {
                    flag=1;
                    printf("%d %d\n",l,r);
                    break;
                }
            }
        }
        //if(T!=0)putchar('\n');
    }
    return 0;
}
