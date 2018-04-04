#include <iostream>

using namespace std;

int main()
{
    int a,b,na=0,nb=0,ans=0;
    int an[10],bn[10];
    cin>>a>>b;
    while(a)
    {
        an[na++]=a%10;
        a/=10;
    }
    while(b)
    {
        bn[nb++]=b%10;
        b/=10;
    }
    for(int i=0;i<na;i++)
    {
        for(int j=0;j<nb;j++)
            ans+=an[i]*bn[j];
    }
    cout<<ans<<endl;
    return 0;
}
