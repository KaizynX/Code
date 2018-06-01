#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
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
        if(flag==true){
            cout<<a<<endl;
        }
    }
    return 0;
}
