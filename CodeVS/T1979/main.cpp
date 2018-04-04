#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,k;cin>>n>>k;
    int a[10000];
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    int ans=a[n-k]-a[k-1];
    if(ans==1||ans==2)cout<<"YES"<<endl<<ans<<endl;
    else if (ans<=0)cout<<"NO"<<endl<<ans<<endl;
    else{
        bool flag=true;
        int sqr=sqrt(ans);
        for(int i=2;i<=sqr;i++){
            if(ans%i==0){
                cout<<"NO"<<endl<<ans<<endl;
                flag=false;
                break;
            }
        }
        if(flag)cout<<"YES"<<endl<<ans<<endl;
    }
    return 0;
}
