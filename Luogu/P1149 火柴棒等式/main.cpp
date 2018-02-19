#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1000;
const int num[]={6,2,5,5,4,5,6,3,7,6};

inline int cul(int a)
{
    if(a==0)return num[0];
    int res=0;
    while(a>0)
    {
        res+=num[a%10];
        a/=10;
    }
    return res;
}

int main()
{
    int n,curi,curj,sum,ans=0;
    scanf("%d",&n);
    n-=4;
    for(int i=0;i<=maxn;++i)
    {
        curi=n-cul(i);
        if(curi<4)continue;
        for(int j=0;j<=maxn;++j)
        {
            curj=curi-cul(j);
            if(curj<2)continue;
            sum=i+j;
            if(curj==cul(sum))
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
