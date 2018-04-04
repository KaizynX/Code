#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=400+5;
const int day[]={0,31,0,31,30,31,30,31,31,30,31,30,31};

int ans[7],n;
int y,m,d,w;

inline bool pd(int y)
{
    if(y%400==0)return 1;
    if(y%4==0 && y%100!=0)return 1;
    return 0;
}

int main()
{
    scanf("%d",&n);
    w=6;//1900 1 13
    ans[w]++;
    for(y=1900;y<1900+n;++y)
    {
        for(m=1;m<=12;++m)
        {
            if(y==1900+n-1 && m==12)break;
            if(m==2)
            {
                if(pd(y))w=(w+29)%7;
                else w=(w+28)%7;
            }
            else w=(w+day[m])%7;
            ans[w]++;
        }
    }
    printf("%d %d ",ans[6],ans[0]);
    for(int i=1;i<=4;++i)
        printf("%d ",ans[i]);
    printf("%d",ans[5]);
    return 0;
}
