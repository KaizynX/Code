#include <iostream>

using namespace std;
int n;

int f(int xin,int lao,int time)
{
    if(time==n)return lao+xin;
    else f(lao,lao+xin,time+1);
}

int main()
{
    cin>>n;
    cout<<f(1,0,1);
    return 0;
}
