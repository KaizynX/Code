#include <iostream>
#include <cstdio>
using namespace std;
const int maxm=2000000+5;

int main()
{
    int m,k,mid;
    scanf("%d",&m);
    k=(m%2+1)%2;
    for(int i=m/2;i>=2;--i)
    {
        if(m/i-i/2<0)continue;
        if(i%2==0)
        {
            if(!(2*m%i==0&&m%i!=0))continue;//m%i==0.5
            mid=m/i;
            printf("%d %d\n",mid-i/2+1,mid+i/2);
        }
        else
        {
            if(m%i!=0)continue;
            mid=m/i;
            printf("%d %d\n",mid-i/2,mid+i/2);
        }
    }
    return 0;
}
