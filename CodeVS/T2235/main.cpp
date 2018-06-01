#include <iostream>

using namespace std;

int main()
{
    int n,p;
    float m;
    cin>>n>>m;
    p=n*m/10;
    if(p%10<5)
        cout<<p-p%10<<endl;
    if(p%10>=5)
       cout<<p+10-p%10<<endl;
    return 0;
}
