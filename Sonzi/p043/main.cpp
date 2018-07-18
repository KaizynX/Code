#include <iostream>

using namespace std;

int main()
{
    int n,k=0,j=1;
    cin>>n;
    while(++k){
        j*=3;
        if (j>n){break;}
    }
    cout<<k-1;
}
