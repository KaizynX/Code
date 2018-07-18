#include <iostream>

using namespace std;

int main()
{
    char a;
    int num=0;
    cin>>a;
    while(a!='#'){
        if((a='a') || (a='A')){
            ++num;
        }
        cin>>a;
    }

    cout<<num<<endl;
    return 0;
}
