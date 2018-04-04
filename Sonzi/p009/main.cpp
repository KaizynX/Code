#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    double s=(a+b)*c/2.0;
    cout<<setprecision(2);
    cout<<setiosflags(ios::fixed);
    cout<<s;
    return 0;
}
