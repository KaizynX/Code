#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,sum=0,a[1000];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        sort(a+i,a+n);
        a[i+1]+=a[i];
        sum+=a[i+1];
    }
    cout<<sum<<endl;
    return 0;
}
