#include <iostream>

using namespace std;

int main()
{
    int n;
    long long a[100];
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<n;++j){
            if(a[j]<a[i])
                swap(a[j],a[i]);
        }
    }
    cout<<a[1]<<" ";
    for(int i=1;i=n;++i){
        for(int j=i+1;j<n;++j){
            if(a[j]>a[i])
                swap(a[j],a[i]);
        }
    }
    cout<<a[1]<<endl;
    return 0;
}
