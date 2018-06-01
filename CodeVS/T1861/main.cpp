#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int sum=0;
    while(n!=1){
        if(n%2==1){
            n=n*3+1;
            sum++;
        }else{
            n/=2;
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
