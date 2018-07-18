#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100;//1000000+5;//没超时，但为什么答案错了
int main()
{
    int n,len=0,a[maxn]={0},b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&b);
        if(b>a[len])a[++len]=b;
        else
        {
            for(int i=1;i<=len;i++)
            {
                if(a[i]>b)
                {
                    a[i]=b;
                    break;
                }
            }
        }
    }
    printf("%d\n",len);
    return 0;
}
