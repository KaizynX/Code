#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    for(int j=a;j>0;--j){
        for(int i=1;i<=2*j-1;++i){
            cout<<"*";
        }
        for(int i=1;i<=2*a+1-2*j;++i){
            cout<<"$";
        }
    cout<<endl;
    }
    return 0;
}
