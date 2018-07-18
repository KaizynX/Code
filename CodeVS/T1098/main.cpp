#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int a[n],b[n];
    int sum=0,step=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int last=sum/n;
    for(int i=0;i<n;i++)b[i]=a[i]-last;
    for(int i=0;i<n-1;i++){
        a[i+1]+=b[i];
        b[i+1]+=b[i];
        if(b[i]==0)continue;
        step++;
    }
    cout<<step;
    return 0;
}
