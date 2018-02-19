#include <iostream>

using namespace std;
int f[50];
int main()
{
    int n;
    cin>>n;
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    if(n==1||n==2)cout<<"1"<<endl;
    else cout<<f[n]<<endl;
    return 0;
}
