#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,v,ans=0,f[10000];
    cin>>n>>v;
    int a[n],b[n];//a大小b喜爱程度
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++){
        for(int j=v;j>=a[i];j--){
            f[j]=max(f[j-a[i]]+b[i],f[j]);
        }
    }
    for(int i=1;i<=v;i++)ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}
