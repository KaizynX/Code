#include <iostream>

using namespace std;

int main()
{
    int n;
    long long a[100],small,big;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    small=a[1];
    big=a[1];
    for(int i=1;i<=n;++i){
        if(a[i]<small){
            small=a[i];
        }
    }
    for(int i=1;i<=n;++i){
        if(a[i]>big){
            big=a[i];
        }
    }
    cout<<small<<" "<<big<<endl;
    return 0;
}
