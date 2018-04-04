#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[15];
int main()
{
    int num=1,sum=0;
    string isbn;
    cin>>isbn;
    a[1]=isbn[0]-'0';
    a[2]=isbn[2]-'0';
    a[3]=isbn[3]-'0';
    a[4]=isbn[4]-'0';
    a[5]=isbn[6]-'0';
    a[6]=isbn[7]-'0';
    a[7]=isbn[8]-'0';
    a[8]=isbn[9]-'0';
    a[9]=isbn[10]-'0';
    if(isbn[12]=='X')
        a[10]=10;
    else
        a[10]=isbn[12]-'0';
    for(int i=1;i<=9;++i)
    {
        sum+=a[i]*i;
        sum%=11;
    }
    if(sum==a[10])
        printf("Right\n");
    else
    {
        for(int i=1;i<=9;++i)
        {
            printf("%d",a[i]);
            if(i==1 || i==4 ||i ==9)
                putchar('-');
        }
        if(sum==10)
            putchar('X');
        else
            printf("%d\n",sum);
    }
    return 0;
}
