#include <iostream>
using namespace std;
int main()
{
    int n=0,i=0;
    char a;
    while(++i){
        cin>>a;
        if(a=' ')++n;
        if(a='.')break;
    }
    cout<<n+1;
    return 0;
}
