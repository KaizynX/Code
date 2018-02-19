#include <iostream>
#define Maxn 100
using namespace std;
long long a[Maxn];
int main()
{
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}
