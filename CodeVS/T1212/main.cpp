#include <iostream>

using namespace std;

int main()
{
    int a,b,gcd;
    cin>>a>>b;
    if(a>b)swap(a,b);
    for(int i=1;i<=a;++i){
        if(a%i==0&&b%i==0)gcd=i;
    }
    cout<<gcd<<endl;
    return 0;
}
