#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char c[13],ans;
    int a[10],sum=0;
    int i=0,j=0,k=1;
    while(i<13)
    {
        c[i]=getchar();
        if(c[i]>='0'&&c[i]<='9')
        {
            a[j]=c[i]-'0';
            if(j!=9)
            {
                sum+=a[j]*k;
                j++;
                k++;
            }
        }
        i++;
    }
    sum%=11;
    if(sum==10)ans='X';
    else ans=sum+'0';
    if(ans==c[12])printf("Right\n");
    else
    {
        for(int i=0;i<12;i++)printf("%c",c[i]);
        printf("%c\n",ans);
    }
    return 0;
}
