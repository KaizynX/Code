#include <iostream>

using namespace std;

int main()
{
    long long a,b,m;
    while(cin>>a>>b>>m)
    {
        long long ans=1,a1=a,b1=b;
        a1%=m;
        while(b1)
        {
            if(b1%2==1)
            {
                ans=ans*a1%m;
            }
            a1=(a1*a1)%m;
            b1/=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
