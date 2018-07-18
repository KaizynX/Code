#include <iostream>

using namespace std;

int main()
{
    int m,n,i;
    cin>>m>>n;
    int k=m;
    if(k>n){
        k=n;
    }
    for(i=k;i>=0;--i){
        if(m%i==0&&n%i==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
