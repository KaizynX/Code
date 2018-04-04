#include <iostream>

using namespace std;
//(m*2+5)*50+y-365==a
int main()
{
    int m,y,a,m1,a1;
    cin>>a;
    m1=(m*2+5)*50;
    a1=a+365;
    for(m=1;m<=12;++m){
        for(y=0;y<=100;++y){
            if((m*2+5)*50+y-365==a){

                cout<<y<<" "<<m<<endl;
                break;
            }
        }
    }

}
