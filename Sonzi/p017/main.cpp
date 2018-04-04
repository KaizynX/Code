#include <iostream>

using namespace std;

int main()
{
   int year,month,a=0;
   cin>>year>>month;
   if((year%400==0) || (year%4==0 && year%100!=0)){
        a=1;
    }
    switch(month){
        case 1:
        case 5:
        case 3:
        case 7:
        case 8:
        case 10:
        case 12:
            cout<<31<<endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout<<30<<endl;
            break;
        case 2:
            cout<<28+a<<endl;
            break;


    }
}
