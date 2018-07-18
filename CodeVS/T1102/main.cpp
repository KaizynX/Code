#include <iostream>

using namespace std;

int main()
{
    int t,m;cin>>t>>m;
    int dt[100],dv[100],f[1001]={0};
    for(int i=0;i<m;++i)cin>>dt[i]>>dv[i];
    for(int i=0;i<m;++i){
        for(int j=t;j>=dt[i];j--){
            f[j]=max(f[j-dt[i]]+dv[i],f[j]);
        }
    }
    int ans=0;
    for(int i=1;i<=t;i++)ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}
