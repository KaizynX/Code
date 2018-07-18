#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(double i=0;i<=5;i=i+0.01){
        if (i*i*i>=n){
        cout<<i;
        break;
        }
    }
    return 0;
}
