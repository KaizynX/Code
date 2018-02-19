#include <iostream>

using namespace std;

int main()
{
    int b,p,k;
    cin>>b>>p>>k;

    int ans=1,b1=b,p1=p;
    b1%=k;
    /*
        (a*b)%c==(a%c)*(b%c)%c
        (b%k)^p %k
        (a^2 %c*a)^(b/2) %c
        ???
    */
    while(p1)
    {
        if(p1%2==1)
        {
            ans=ans*b1%k;
        }
        b1=(b1*b1)%k;
        p1/=2;
    }

    cout<<b<<"^"<<p<<" mod "<<k<<"="<<ans<<endl;
    return 0;
}
