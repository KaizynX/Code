#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >>n;
    double a,s=0;
    for(int i=1;i<=n;++i){
        a=1.0/i;
        s=s+a;
    }
    cout<<setprecision(6)<<fixed<<s<<endl;
    return 0;
}
