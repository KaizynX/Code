#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,c;
    double s,p;
    cin>>a>>b>>c;
    p=(a+b+c)/2;
    if(a+b>c && a+c>b && b+c>a){
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.2f",s);
    }
    else cout<<"Data Error";
    return 0;
}
