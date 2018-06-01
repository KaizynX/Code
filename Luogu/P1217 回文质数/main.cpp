#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxl=8;
int a,b,la,lb;
int n[4]={1,3,7,9};

inline int len(int num)
{
    int l=0;
    while(num)
    {
        l++;
        num/=10;
    }
    return l;
}

bool prime(int num)
{
    for(int i=2;i<=sqrt(num)+0.005;++i)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void solve(int l)
{
    int num;
    if(l==1)
    {
        if(a<=5)printf("5\n");
        if(a<=7)printf("7\n");
    }
    else if(l==2)
    {
        if(a<=11)printf("11\n");
    }
    else if(l==3)
    {
        for(int i1=0;i1<4;++i1)
            for(int i2=0;i2<=9;++i2)
            {
                num=101*n[i1]+10*i2;
                if(a<=num && b>=num &&prime(num))
                    printf("%d\n",num);
            }
    }
    else if(l==4)
    {
        for(int i1=0;i1<4;++i1)
            for(int i2=0;i2<=9;++i2)
            {
                num=1001*n[i1]+110*i2;
                if(a<=num && b>=num &&prime(num))
                    printf("%d\n",num);
            }
    }
    else if(l==5)
    {
        for(int i1=0;i1<4;++i1)
            for(int i2=0;i2<=9;++i2)
                for(int i3=0;i3<=9;++i3)
                {
                    num=10001*n[i1]+1010*i2+100*i3;
                    if(a<=num && b>=num &&prime(num))
                        printf("%d\n",num);
                }
    }
    else if(l==6)
    {
        for(int i1=0;i1<4;++i1)
            for(int i2=0;i2<=9;++i2)
                for(int i3=0;i3<=9;++i3)
                {
                    num=100001*n[i1]+10010*i2+1100*i3;
                    if(a<=num && b>=num &&prime(num))
                        printf("%d\n",num);
                }
    }
    else if(l==7)
    {
        for(int i1=0;i1<4;++i1)
            for(int i2=0;i2<=9;++i2)
                for(int i3=0;i3<=9;++i3)
                    for(int i4=0;i4<=9;++i4)
                    {
                        num=1000001*n[i1]+100010*i2+10100*i3+1000*i4;
                        if(a<=num && b>=num &&prime(num))
                            printf("%d\n",num);
                    }
    }
    else if(l==8)
    {
        for(int i1=0;i1<4;++i1)
            for(int i2=0;i2<=9;++i2)
                for(int i3=0;i3<=9;++i3)
                    for(int i4=0;i4<=9;++i4)
                    {
                        num=10000001*n[i1]+1000010*i2+100100*i3+11000*i4;
                        if(a<=num && b>=num &&prime(num))
                            printf("%d\n",num);
                    }
    }
}

int main()
{
    scanf("%d%d",&a,&b);
    la=len(a);
    lb=len(b);
    for(int i=la;i<=lb;++i)
    {
        solve(i);
    }
    return 0;
}
