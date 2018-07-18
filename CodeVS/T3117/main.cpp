#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int c[1005]={0};
    string a,b;
    cin>>a>>b;
    int la=a.length(),lb=b.length();
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            c[i+j-1]+=(a[la-i]-'0')*(b[lb-j]-'0');
            if(c[i+j-1]>=10)
            {
                c[i+j]+=c[i+j-1]/10;
                c[i+j-1]%=10;
            }
        }
    }
    if(c[la+lb])cout<<c[la+lb];
    for(int i=la+lb-1;i>0;i--)cout<<c[i];
    return 0;
}
