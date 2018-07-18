#include <iostream>

using namespace std;

int main()
{
    int m,a,b,c;
    for(int i=100;i<=999;i++){
        m=i;
        a=m/100;
        b=m/10%10;
        c=m%10;
        if(a*a*a+b*b*b+c*c*c==m){
            cout<<m<<endl;
        }
    }
}
