#include <iostream>

using namespace std;

int main()
{
    int h,f,c,r;//head feet chicken ribbit
    cin>>h>>f;
    for(c=0;c<=h;c++){
        r=h-c;
        if(2*c+4*r==f){
            cout<<c<<" "<<r<<endl;
        }
    }
    return 0;
}
