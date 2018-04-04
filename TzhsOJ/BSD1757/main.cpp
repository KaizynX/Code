#include <iostream>

using namespace std;
int res=0,n;

void f(int cur)
{
    if(cur==n)res++;
    else if(cur>n)return;
    else
    {
        f(cur+1);
        f(cur+2);
    }
}

int main()
{
    cin>>n;
    f(0);
    cout<<res<<endl;
    return 0;
}
