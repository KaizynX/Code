#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[10]={512,256,128,64,32,16,8,4,2,1};
    int n;
    cin>>n;
    cout<<lower_bound(a,a+9,n,greater<int>() )-a;
    return 0;
}
