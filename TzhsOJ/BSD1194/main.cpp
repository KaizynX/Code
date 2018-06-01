#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int b,p,k;
    cin>>b>>p>>k;
    int ans=b%k;
    for(int i=1;i<p;i++)
    {
        ans*=b;
        ans%=k;
    }
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<ans<<endl;
    return 0;
}
