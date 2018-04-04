#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int i,ab,cd,e[3],a,b,c,d,f;
    for(i=1000;i<=9999;++i){
        ab=i/100;
        cd=i%100;
        if((ab+cd)*(ab+cd)==i){
            for(f=0;f<=3;++f){
            e[f]=i;
            }
        }
    }
    for(f=0;f<=3;++f)
    {
    a=e[f]/1000;
    b=(e[f]/100)%10;
    c=(e[f]%100)/10;
    d=e[f]%10;
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<endl;
    }
    return 0;
}
