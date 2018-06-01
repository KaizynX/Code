#include <iostream>

using namespace std;
int a[105],num;
int main()
{
    a[num]=1;
    while(a[num])
    {
        cin>>a[++num];
    }
    for(int i=num-1;i>=1;--i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
