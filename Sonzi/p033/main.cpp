#include <iostream>

using namespace std;

int main()
{
    int j,b,x,r;
    for(j=0;j<=10;++j){
        for(b=0;b<=50;++b){
            r=50-5*j-1*b;
            x=r*10*3;
            if(x+j+b==100)
            cout<<j<<" "<<b<<" "<<x<<endl;
        }
    }
    return 0;
}
