#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a,b;
    char c;
    cin>>a>>b>>c;
    cout<<setprecision(2);
    cout<<setiosflags(ios::fixed);
    switch(c){
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            cout<<a/b<<endl;
            break;
        default:
            break;
    }

}
