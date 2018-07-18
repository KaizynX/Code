#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a ){
        if(a*a==b*b+c*c || a*a+b*b==c*c || a*a+c*c==b*b){cout<<"Yes!"<<endl;
        }else{
        cout<<"No!";
        }
    }else{cout<<"Error!";}

    return 0;
}
