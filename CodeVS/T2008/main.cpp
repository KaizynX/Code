#include <iostream>
using namespace std;
int main()
{
    long long year,month,day,hour,minute,second,time;
    char c1,c2,c3,c4;
    cin>>year>>c1>>month>>c2>>day>>hour>>c3>>minute>>c4>>second>>time;
    second+=time;
    if(second>=60){
        minute+=second/60;
        second%=60;
    }
    if(minute>=60){
        hour+=minute/60;
        minute%=60;
    }
    if(hour>=24){
        day+=hour/24;
        hour%=24;
    }
    while(1){
        if(year%4==0&&year%100!=0||year%400==0){
            if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
                if(day>31){
                    day-=31;
                    month++;
                }else break;
            }
            if(month==4||month==6||month==9||month==11){
                if(day>30){
                    day-=30;
                    month++;
                }else break;
            }
            if(month==2){
                if(day>29){
                    day-=29;
                    month++;
                }else break;
            }
            if(month>12){
                year++;
                month-=12;
            }
        }
        else {
            if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
                if(day>31){
                    day-=31;
                    month++;
                }else break;
            }
            if(month==4||month==6||month==9||month==11){
                if(day>30){
                    day-=30;
                    month++;
                }else break;
            }
            if(month==2){
                if(day>28){
                    day-=28;
                    month++;
                }else break;
            }
            if(month>12){
                year++;
                month-=12;
            }
        }
    }
    cout<<year<<c1;
    if(month<10)cout<<0<<month<<c2;
    else cout<<month<<c2;
    if(day<10)cout<<0<<day<<" ";
    else cout<<day<<" ";
    if(hour<10)cout<<0<<hour<<c3;
    else cout<<hour<<c3;
    if(minute<10)cout<<0<<minute<<c3;
    else cout<<minute<<c3;
    if(second<10)cout<<0<<second<<endl;
    else cout<<second<<endl;
    return 0;
}
