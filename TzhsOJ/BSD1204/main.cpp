#include <iostream>

using namespace std;
int w[7001],p[7001],f[7001];
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=n;++i)cin>>p[i];
    for(int i=1;i<=n;++i){
        for(int j=m;j>=w[i];--j){
            f[j]=max(f[j],f[j-w[i]]+p[i]);
        }
    }
    for(int i=1;i<=n;++i)ans=max(f[i],ans);
    return 0;
}
