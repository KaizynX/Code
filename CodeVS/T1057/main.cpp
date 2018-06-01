#include <iostream>

using namespace std;

int main()
{
    int a[13]={0};
    int rest=0,mama=0,b;
    bool flag=true;
    for(int i=1;i<=12;++i)cin>>a[i];
    for(int i=1;i<=12;++i){
        rest+=300;
        rest-=a[i];
        if(rest<0){
            cout<<-i;
            flag=false;
            break;
        }
        b=rest/100;
        rest%=100;
        mama+=100*b;
    }
    if(flag)cout<<mama*1.2+rest;
    return 0;
}
