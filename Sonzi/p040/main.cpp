#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >>n;
    double a,s;
    for(int i=1;i<=n;++i){
        a=1/i;
        s+=a;
    }
    printf("%.6f",s);
    return 0;
}
