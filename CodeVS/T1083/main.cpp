#include <iostream>

using namespace std;

int main()
{
    int i=0,line,rest,he/*ºÍ*/,a,b;
    long long n,sum;
    cin>> n;
    while(++i){
        sum=(1+i)*i/2;
        if(n<=sum){
            line=i;
            break;
        }
    }
    he=line+1;
    rest=n-(line-1)*line/2;
    if(line%2==1){
        a=he-rest;
        b=he-a;
    }else{
        a=rest;
        b=he-a;
    }
    cout<<a<<"/"<<b<<endl;
    return 0;
}
