#include <iostream>
#include<cstdio>
using namespace std;

int main()
{

    double t1,t2,a,b,c,d;
    cin>>a>>b>>c>>d;
    t1=1/(1/a+1/b);
    t2=1/(1/a+1/b+1/c+1/d);
    printf("%.2f\n%.2f",t1,t2);
}
