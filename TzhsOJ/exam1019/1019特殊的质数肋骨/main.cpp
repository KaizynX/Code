#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=8+2;

int n,zhishu[4]={2,3,5,7};

bool pd(int a)
{
    for(int i=2;i<=sqrt(a)+0.05;++i)
    {
        if(a%i==0)return 0;
    }
    return 1;
}

void dfs(int cur,int num)
{
    if(cur>n)
    {
        printf("%d\n",num);
        return;
    }

    int now;
    for(int i=1;i<=9;i=i+2)
    {
        now=num*10+i;
        if(pd(now))
            dfs(cur+1,now);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<4;++i)
        dfs(2,zhishu[i]);
    return 0;
}
