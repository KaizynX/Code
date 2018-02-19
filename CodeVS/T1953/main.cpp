#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,flag,sqr;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        flag=1;
        sqr=sqrt(i)+0.5;
        for(int j=2;j<=sqr;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(i==2||flag)cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
