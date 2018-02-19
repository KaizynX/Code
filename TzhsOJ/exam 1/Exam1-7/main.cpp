#include <iostream>

using namespace std;
int year,day=13,d[7];
const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int pd/*ÅÐ¶ÏÈòÄê*/(int year)
{
    if(year%400==0 ||(year%4==0)&&(year%100!=0))return 1;
    else return 0;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        year=1900+i;
        for(int m=1;m<=12;m++){
            d[day%7]++;
            day+=month[m];
            if(m==2){day+=pd(year);}
        }
    }
    for(int i=6;i<12;i++){
        cout<<d[i%7]<<" ";
    }
    cout<<d[5];
    return 0;
}
