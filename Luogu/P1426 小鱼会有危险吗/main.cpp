#include <iostream>
#include <cstdio>
using namespace std;
const double d=0.98;
int main()
{
    bool flag=0;
    double v=7,now=0,s,x;
    cin>>s>>x;
    if(now>=s-x)
        flag=1;
    while(now<s+x)
    {
        now+=v;
        if(flag==1)
        {
            if(now<=s+x)
                printf("y\n");
            else
                printf("n\n");
            return 0;
        }
        if(now>=s-x)
            flag=1;
        v*=d;
    }
    printf("n\n");
    return 0;
}
