#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool flag=true;
    int b=sqrt(n);
    for(int j =2;j<=b;j++){
        if(n%j==0){
            flag=false;
            break;
        }
    }
    if(n==1)cout<<"\\n"<<endl;
    else if(flag)cout<<"\\t"<<endl;
    else cout<<"\\n"<<endl;
    /*int a,b;
    for(int i=2;i<100;i++){
        a=i;
        b=sqrt(a)+0.0005;
        bool flag=true;
        for(int j =2;j<=b;j++){
            if(a%j==0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<a<<endl;
        }
    }*/
    return 0;
}
