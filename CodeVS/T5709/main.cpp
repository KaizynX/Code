#include<iostream>
//#include<cstring>

using namespace std;

int main()
{
    int n,s,ans=0,w[10000],k[10000],f[10000]={0};//注释处功能与f[10000]={0}相同
    cin>>s>>n;
    for(int i=0;i<n;i++)cin>>w[i]>>k[i];
    //memset(f,0,sizeof(f));
    for(int i=0;i<n;i++){
        for(int j=s;j>=w[i];j--){
            f[j]=max(f[j-w[i]]+k[i],f[j]);
        }
    }
    for(int i=1;i<=s;i++)ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}
