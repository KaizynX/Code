#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=10000000+5;
const int maxm =5000;

int main()
{
    int n,sum=1,cur=0,a,b,flag;
    cin>>n;
    while(n>cur)
    {
        cur+=sum;
        sum++;
    }
    flag=sum%2;
    if(flag)
    {
        b=1;a=sum-1;
    }
    else
    {
        a=1;b=sum-1;
    }
    while(n<cur)
    {
        if(flag)
        {
            a--;b++;
        }
        else
        {
            a++;b--;
        }
        cur--;
    }
    printf("%d/%d\n",a,b);
    return 0;
}
