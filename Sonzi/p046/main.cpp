#include <iostream>

using namespace std;

int main()
{
    int x,n=0,j=0;
    cin>>x;
    while(++n){
        j+=n*n;
        if(j>x){
            cout<<n-1;
            break;
        }
    }
    return 0;
}
