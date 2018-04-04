#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    double a,b;
    cin>>a;
    cout<<setprecision(2);
    cout<<setiosflags(ios::fixed);
    if(a<1000){
        cout<<a*0.95<<endl;
    }else{
        cout<<(a-1000)*0.9+950;
    }


    return 0;
}
