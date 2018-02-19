#include <iostream>

using namespace std;

int main()
{
    int r;cin>>r;
    int a[1001][1001]={0};
    for(int i=1;i<=r;++i){
        for(int j=1;j<=i;++j)cin>>a[i][j];
    }
    for(int i=r-1;i>=1;--i){
        for(int j=1;j<=i;++j){
            a[i][j]=max(a[i][j]+a[i+1][j],a[i][j]+a[i+1][j+1]);
        }
    }
    cout<<a[1][1];
    return 0;
}
