#include <iostream>

using namespace std;

int main()
{
    int n,i,a,b,j;
    cin>>n;
    for(i=n;i>0;i--){
        a=2*i-1;
        b=n-i;
        for(j=b;j>0;j--){
            cout<<" ";
        }
        for(j=a;j>0;j--){
            cout<<"#";
        }
        cout<<endl;
    }
    return 0;
}
