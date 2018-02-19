#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int n,sa=0;
    double sz=0;
    cin>>n;
    cout<<setprecision(2)<<fixed;
    int a[n+1];
    double b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        sz+=a[i]*b[i];
        sa+=a[i];
    }
    cout<<sz/sa<<endl;
    return 0;
}
