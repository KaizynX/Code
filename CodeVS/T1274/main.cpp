#include <iostream>
//ÕâÌâÓÐ¶¾
using namespace std;

int main()
{
    int l,m,over;
    cin>>l>>m;
    cout<<"Enter the speed limit: Enter the recorded speed of the car: ";
    over=m-l;
    if(over>0){
        if(over>=1&&over<=20)cout<<"You are speeding and your fine is $ 100"<<endl;
        else if(over>=21&&over<=30)cout<<"You are speeding and your fine is $ 270"<<endl;
        else cout<<"You are speeding and your fine is $ 500"<<endl;
    }else cout<<"Congratulations, you are within the speed limit"<<endl;
    return 0;
}
